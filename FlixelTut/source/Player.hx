package ;

import flixel.FlxSprite;
import flixel.util.FlxAngle;
import flixel.util.FlxColor;
import flixel.FlxG;
import flixel.util.FlxPoint;
import flixel.FlxObject;
import flixel.util.FlxVelocity;

/**
 * ...
 * @author ...
 */
class Player extends FlxSprite
{
	public var speed:Float = 200;
	public function new(X:Float=0, Y:Float=0) 
	{
		super(X, Y);
		//makeGraphic(16, 30, FlxColor.BLUE);
		loadGraphic(AssetPaths.player__png, true, 16, 16);
		// 不明白这两句是什么意思?
		setFacingFlip(FlxObject.LEFT, false, false);
		setFacingFlip(FlxObject.RIGHT, true, false);
		
		animation.add("lr", [3, 4, 3, 5], 6, false);
		animation.add("u", [6, 7, 6, 8], 6, false);
		animation.add("d", [0, 1, 0, 2], 6, false);
		drag.x = drag.y = 1600;
	}
	
	private function movement():Void {
		var _up:Bool = false;
		var _down:Bool = false;
		var _right:Bool = false;
		var _left:Bool = false;
		
		_up = FlxG.keys.anyPressed(["UP", "W"]);
		_down = FlxG.keys.anyPressed(["DOWN", "S"]);
		_right = FlxG.keys.anyPressed(["RIGHT", "D"]);
		_left = FlxG.keys.anyPressed(["LEFT", "A"]);
		
		if (_up && _down) {
			_up = _down = false;
		}
		if (_right && _left) {
			_right = _left = false;
		}
		
		// 正在运动中
		
		if (_up || _down || _right || _left) {
			var dire:Int = 0;
			var mA:Float = 0;
			if (_up) {
				mA = -90;
				if (_left) {
					mA -= 45; 
				}else if (_right) {
					mA += 45;
				}
				facing = FlxObject.UP;
			}else if (_down) {
				mA = 90;
				if (_left) {
					mA += 45;
				}else if (_right) {
					mA -= 45;
				}
				facing = FlxObject.DOWN;
			}else if (_right) {
				mA = 0;
				facing = FlxObject.RIGHT;
			}else if (_left) {
				mA = 180;
				facing = FlxObject.LEFT;
			}
			// 设置速度
			velocity = FlxVelocity.velocityFromAngle(mA, speed);
			//angle = mA;
			
			if ((velocity.x != 0 || velocity.y != 0 ) && touching == FlxObject.NONE) {
				switch(facing) {
					case FlxObject.LEFT, FlxObject.RIGHT:
						animation.play("lr");
					case FlxObject.UP:
						animation.play("u");
					case FlxObject.DOWN:
						animation.play("d");
				}
			}
		}
		
	}
	
	override public function update():Void 
	{
		movement();
		super.update();
	}
}