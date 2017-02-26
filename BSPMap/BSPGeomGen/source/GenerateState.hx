package;
import flixel.FlxSprite;
import flixel.FlxState;
import openfl.display.BitmapData;
import flash.geom.Rectangle;
import flixel.FlxG;
import flixel.util.FlxColor;
import flixel.ui.FlxButton;
import flixel.util.FlxRandom;
/**
 * ...
 * @author ...
 */
class GenerateState extends FlxState
{
	static inline var TILE_SIZE:Int = 16;
	public static var mapData:BitmapData;
	
	var rooms:Array<Rectangle>;
	var hallways:Array<Rectangle>;
	var leafs:Array<Leaf>;
	var mapSprite:FlxSprite;
	var mapWidth:Int;
	var mapHeight:Int;
	
	override public function create():Void 
	{
		trace("hello");
		mapWidth = Std.int(FlxG.width / TILE_SIZE);
		mapHeight = Std.int(FlxG.height / TILE_SIZE);
		//mapWidth = Std.int(FlxG.width);
		//mapHeight = Std.int(FlxG.height);
		
		// 创建一个sprite用来显示地图
		mapSprite = new FlxSprite(FlxG.width / 2 - (mapWidth / 2), FlxG.height / 2 - (mapHeight / 2));
		mapSprite.makeGraphic(mapWidth, mapHeight, FlxColor.BLACK);
		// 用来设置什么的呢?
		mapSprite.scale.set(TILE_SIZE, TILE_SIZE);
		add(mapSprite);
		
		// 设置ui
		var gutter:Int = 10;
		add(new FlxButton(gutter, gutter, "Generate", generateMap));
		add(new FlxButton(gutter * 2 + 80, gutter, "Play", play));
		
		if (mapData == null) {
			generateMap();
		} else {
			updateSprite();
		}
		super.create();
	}
	
	override public function update():Void 
	{
		super.update();
		trace("update");
		if (FlxG.keys.justReleased.G) {
			
			generateMap();
		}
		if (FlxG.keys.justReleased.P) {
			play();
		}
	}
	
	function generateMap():Void {
		// Reset mapData
		mapData = new BitmapData(mapWidth, mapHeight, false, FlxColor.BLACK);

		// Reset arrays
		rooms = [];
		hallways = [];
		leafs = [];

		// First, create leaf to be root of all leaves
		var root = new Leaf(0, 0, mapWidth, mapHeight);
		leafs.push(root);

		var didSplit:Bool = true;
		// Loop through every Leaf in array until no more can be split
		while (didSplit)
		{
			didSplit = false;
			
			for (leaf in leafs)
			{
				if (leaf.leftChild == null && leaf.rightChild == null) // If not split
				{
					// If this leaf is too big, or 75% chance
					if (leaf.width > Leaf.MAX_SIZE || leaf.height > Leaf.MAX_SIZE || FlxRandom.float() > 0.25)
					{
						if (leaf.split()) // split the leaf!
						{
							// If split worked, push child leafs into vector
							leafs.push(leaf.leftChild);
							leafs.push(leaf.rightChild);
							didSplit = true;
						}
					}
				}
			}
		}

		// Next, iterate through each leaf and create room in each one
		root.createRooms();

		for (leaf in leafs)
		{
			// Then draw room and hallway (if there is one)
			if (leaf.room != null)
			{
				drawRoom(leaf.room);
			}

			if (leaf.hallways != null && leaf.hallways.length > 0)
			{
				drawHalls(leaf.hallways);
			}
		}
		
		updateSprite();
	}
	
	function drawRoom(room:Rectangle):Void {
		rooms.push(room);
		mapData.fillRect(room, FlxColor.WHITE);
	} 
	
	function drawHalls(hallRect:Array<Rectangle>):Void {
		for (hallway in hallRect) {
			hallways.push(hallway);
			mapData.fillRect(hallway, FlxColor.WHITE);
		}
	}
	
	function updateSprite() {
		mapSprite.pixels = mapData.clone();
		mapSprite.dirty = true;
	}
	
	function play() {
		FlxG.switchState(new PlayState());
	}
	
}