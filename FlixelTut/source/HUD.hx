package ;
import flixel.group.FlxTypedGroup;
import flixel.FlxSprite;
import flixel.text.FlxText;
import flixel.FlxG;
import flixel.util.FlxColor;
using flixel.util.FlxSpriteUtil;
import flixel.util.FlxSpriteUtil.DrawStyle;

/**
 * ...
 * @author ...
 */
class HUD extends FlxTypedGroup<FlxSprite>
{
	private var _sprBack:FlxSprite;
	private var _txtMoney:FlxText;
	private var _txtHealth:FlxText;
	private var _sprMoney:FlxSprite;
	private var _sprHealth:FlxSprite;
	
	public function new() 
	{
		super();
		_sprBack = new FlxSprite().makeGraphic(FlxG.width, 20, FlxColor.BLACK);
		_sprBack.drawRect(0, 19, FlxG.width, 1, FlxColor.WHITE);
		_txtHealth  = new FlxText(16, 2, FlxG.width, "3 / 3", 8);
		//_txtHealth.setBorderStyle(, FlxColor.GRAY, 1, 1);
		_txtMoney = new FlxText(0, 2, FlxG.width, "0", 8);
		//_txtMoney.setBorderStyle(SHADOW, FlxColor.GRAY, 1, 1);
		_sprHealth = new FlxSprite(4, _txtHealth.y + (_txtHealth.height / 2) - 4, AssetPaths.health__png);
		_sprMoney = new FlxSprite(FlxG.width - 12, _txtMoney.y + (_txtMoney.height / 2) - 4, AssetPaths.health__png);
		_txtMoney.alignment = "right";
		_txtMoney.x = _sprMoney.x - _txtMoney.width - 4;
		add(_sprBack);
		add(_txtHealth);
		add(_txtMoney);
		add(_sprHealth);
		add(_sprMoney);
		// 对HUD里面的元素设置scrollFactor的x和y,即使摄像机发生了变动，这些元素也会待在原地
		forEach(function(spr:FlxSprite) {
			spr.scrollFactor.set(0,0);
		});
	}
	
}