package;

import flixel.FlxSprite;
import flixel.group.FlxTypedGroup;
import flixel.util.FlxRandom;
import flixel.FlxG;

/**
 * ...
 * @author AlexanderBrain
 */
class MySpriteGroup extends FlxTypedGroup<FlxSprite>
{

	public function new(MaxSize:Int=50) 
	{
		super();
		
		for (i in 0...MaxSize){
			var sprite = new FlxSprite(FlxRandom.floatRanged(0, FlxG.width), FlxRandom.floatRanged(0, FlxG.height));
			sprite.velocity.set(FlxRandom.floatRanged( -50, 50), FlxRandom.floatRanged( -50, 50));
			add(sprite);
		}
		
	}
	
	override public function update():Void 
	{
		super.update();
		
		for (sprite in members)
		{
			if (sprite.x < 0)
			{
				sprite.x = 0;
				sprite.velocity.x *= -1;
			}
			else if (sprite.x + sprite.width > FlxG.width)
			{
				sprite.x = FlxG.width - sprite.width;
				sprite.velocity.x *= -1;
			}
			if (sprite.y < 0)
			{
				sprite.y = 0;
				sprite.velocity.y *= -1;
			}
			else if (sprite.y + sprite.height > FlxG.height)
			{
				sprite.y = FlxG.height - sprite.height;
				sprite.velocity.y *= -1;
			}
		}
	}
}