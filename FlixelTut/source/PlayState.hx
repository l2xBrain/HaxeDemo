package;

import flixel.addons.editors.tiled.TiledMap;
import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.text.FlxText;
import flixel.tile.FlxTilemap;
import flixel.ui.FlxButton;
import flixel.util.FlxMath;
import flixel.FlxObject;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var _player:Player;
	private var _map:TiledMap;
	private var _mWalls:FlxTilemap;
	private var _hud:HUD;
	private var _money:Int = 0;
	private var _health:Int = 3;
	/**
	 * Function that is called up when to state is created to set it up. 
	 */
	override public function create():Void
	{
		_map = new TiledMap(AssetPaths.gameTile__tmx);
		_mWalls = new FlxTilemap();
		// 加载地图怎么添加呢？
		/*_mWalls.loadMap(AssetPaths.gameTile__tmx,"walls, entities");
		_mWalls.follow();
		_mWalls.setTileProperties(2, FlxObject.NONE);
		_mWalls.setTileProperties(3, FlxObject.ANY);
		add(_mWalls);*/
		_player = new Player(20, 20);
		add(_player);
		_hud = new HUD();
		add(_hud);
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
	}	
}