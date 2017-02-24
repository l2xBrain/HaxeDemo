package ;
import flixel.FlxSprite;

/**
 * ...
 * @author Alexander
 */
class Player extends FlxSprite
{

	public function new(x:Float, y:Float) 
	{
		super(x, y, AssetPaths.player__png);
		pixelPerfectRender = false;
		
		setSize(12, 12);
		centerOffsets();
	}
	
	override public function update():Void 
	{
		super.update();
		
		if (FlxG.keys.anyPressed([A, LEFT]))
		{
			velocity.x = -SPEED;
		}
		else if (FlxG.keys.anyPressed([D, RIGHT]))
		{
			velocity.x = SPEED;
		}
		else
		{
			velocity.x = 0;
		}

		if (FlxG.keys.anyPressed([W, UP]))
		{
			velocity.y = -SPEED;
		}
		else if (FlxG.keys.anyPressed([S, DOWN]))
		{
			velocity.y = SPEED;
		}
		else
		{
			velocity.y = 0;
		}
		
		
	}
	
}