package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.util.FlxStringUtil;
import flixel.util.FlxPoint;
import flixel.util.FlxRandom;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	
	static inline var TILE_SIZE:Int = 16;
	
	var map:FlxTilemap;
	var player:Player;
	
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		map = new FlxTilemap();
		var csvData:String = FlxStringUtil.bitmapToCSV(GenerateState.mapData);
		
		map.loadMap(csvData, "assets/images/tiles.png", TILE_SIZE, TILE_SIZE, 0);
		add(map);
		
		// 获取空白处的坐标
		var emptyTile:Array<FlxPoint> = map.getTileCoords(0, false);
		var randomEmptyTile:FlxPoint = emptyTile[FlxRandom.intRanged(0, emptyTile.length)];
		
		add(new Player(randomEmptyTile.x, randomEmptyTile.y));
		
		var gutter:Int = 10;
		add(new FlxButton(gutter, gutter, "Back(Space)", back));
		super.create();
	}
	
	/**
	 * Function that is called when this state is destroyed - you might want to 
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();
		FlxG.collide(player, map);
		
		if (FlxG.keys.justReleased.SPACE)
		{
			back();
		}
	}
	
	public function back():Void {
		FlxG.switchState(new GenerateState());
	}
}