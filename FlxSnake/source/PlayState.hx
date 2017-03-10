package;

import flixel.FlxG;
import flixel.FlxSprite;
import flixel.FlxState;
import flixel.group.FlxSpriteGroup;
import flixel.text.FlxText;
import flixel.FlxObject;
import flixel.util.FlxPoint;
import flixel.util.FlxColor;
import flixel.util.FlxSpriteUtil;
import flixel.util.FlxTimer;
import flixel.util.FlxRandom;
import flixel.system.FlxAssets;

class PlayState extends FlxState {
	private static inline var MIN_INTERVAL:Float = 2;
	private static inline var BLOCK_SIZE:Int = 8;
	
	private var _scoreText:FlxText;
	private var _fruit:FlxSprite;
	private var _snakeHead:FlxSprite;
	private var _snakeBody:FlxSpriteGroup;
	
	private var _headPositions:Array<FlxPoint>;
	private var _movementInterval:Float = 8;
	private var _score:Int = 0;
	
	private var _currenDirection = FlxObject.LEFT;
	private var _nextDirection:Int = FlxObject.LEFT;
	
	//private var _Timer:
	
	
	override public function create():Void 
	{
		FlxG.mouse.visible = false;
		
		var screenMiddleX:Int = Math.floor(FlxG.width / 2);
		var screenMiddleY:Int = Math.floor(FlxG.height / 2);
		
		// create the head of snake
		_snakeHead = new FlxSprite(screenMiddleX - BLOCK_SIZE * 2, screenMiddleY);
		_snakeHead.makeGraphic(BLOCK_SIZE - 2, BLOCK_SIZE - 2, FlxColor.LIME);
		// 设置碰撞模型
		offestSprite(_snakeHead);
		
		// This array stores the recent head positions to update segment positions step by step
		_headPositions = [];
		trace("设置headPositions的位置:"+_headPositions);
		
		// The group holding the body segments
		_snakeBody = new FlxSpriteGroup();
		add(_snakeBody);
		
		// 开始的时候增加三个身体的长度
		for (i in 0...3) {
			addSegment();
			
			moveSnake();
		}
		
		add(_snakeHead);
		
		_fruit = new FlxSprite();
		_fruit.makeGraphic(BLOCK_SIZE - 2, BLOCK_SIZE -2, FlxColor.RED);
		randomizeFruitPosition();
		offestSprite(_fruit);
		add(_fruit);
		
		
		_scoreText = new FlxText(0, 0, 200, "Score:" + _score);
		
		add(_scoreText);
		
		resetTimer();
		
		super.create();
	}
	
	
	override public function update():Void 
	{
		super.update();
		
		if (_scoreText.alpha < 1) {
			_scoreText.alpha += 0.1;
		}
		
		if (!_snakeHead.alive) {
			if (FlxG.keys.anyJustReleased(['SPACE','R'])) {
				FlxG.resetState();
			}
			return;
		}
		
		FlxG.overlap(_snakeHead, _fruit, collectFruit);
		
		FlxG.overlap(_snakeHead, _snakeBody, gameOver);
		
		if (FlxG.keys.anyPressed(["UP", "W"]) && _currenDirection != FlxObject.DOWN) {
			_nextDirection = FlxObject.UP;
		} else if (FlxG.keys.anyPressed(["DOWN", "D"]) && _currenDirection != FlxObject.UP) {
			_nextDirection = FlxObject.DOWN;
		} else if (FlxG.keys.anyPressed(["LEFT", "A"]) && _currenDirection != FlxObject.RIGHT) {
			_nextDirection = FlxObject.LEFT;
		} else if (FlxG.keys.anyPressed(["RIGHT", "F"]) && _currenDirection != FlxObject.LEFT) {
			_nextDirection = FlxObject.RIGHT;
		}
		
	}
	
	override public function destroy():Void 
	{
		super.destroy();
	}
	
	private function collectFruit(Object1:FlxObject, Object2:FlxObject):Void {
		_score += 10;
		updateScore("Score:" + _score);
		
		FlxG.sound.load(FlxG.sound.play('assets/sounds/flixel.wav'));
		
		randomizeFruitPosition();
		
		addSegment();
		
		if (_movementInterval >= MIN_INTERVAL){
			_movementInterval -= 1;
		}
	}
	
	
	private function gameOver(Object1:FlxObject, Object2:FlxObject):Void {
		_snakeHead.alive = false;
		
	}
	//offset 用来设置hitbox的位置
	private function offestSprite(Sprite:FlxSprite):Void {
		Sprite.offset.set(1, 1);
		Sprite.centerOffsets();
	}
	
	private function addSegment():Void {
		var segment:FlxSprite = new FlxSprite( -20 , 20);
		segment.makeGraphic(BLOCK_SIZE - 2, BLOCK_SIZE - 2, FlxColor.GREEN);
		_snakeBody.add(segment);
	}
	
	private function moveSnake():Void {
		_headPositions.unshift(FlxPoint.get(_snakeHead.x, _snakeHead.y));
		
		if (_headPositions.length > _snakeBody.members.length) {
			_headPositions.pop();
		}
		
		
		switch(_nextDirection) {
			case FlxObject.LEFT:
				_snakeHead.x -= BLOCK_SIZE;
			case FlxObject.RIGHT:
				_snakeHead.x += BLOCK_SIZE;
			case FlxObject.UP:
				_snakeHead.y -= BLOCK_SIZE;
			case FlxObject.DOWN:
				_snakeHead.y += BLOCK_SIZE;
		}
		
		_currenDirection = _nextDirection;
		
		FlxSpriteUtil.screenWrap(_snakeHead);
		// 重设_snakeBody的位置
		for (i in 0..._headPositions.length) {
			_snakeBody.members[i].setPosition(_headPositions[i].x, _headPositions[i].y);
		}
	}
	
	private function resetTimer(?Timer:FlxTimer):Void {
		if (!_snakeHead.alive && Timer != null) {
			Timer.destroy();
			return;
		}
		// 设置调用moveSnake的时间顺序
		new FlxTimer().start(_movementInterval / FlxG.updateFramerate, resetTimer);
		moveSnake();
	}
	
	private function randomizeFruitPosition(?Object1:FlxObject, ?Object2:FlxObject) {
		_fruit.x = FlxRandom.intRanged(0, Math.floor(FlxG.width / 8) - 1) * 8;
		_fruit.y = FlxRandom.intRanged(0, Math.floor(FlxG.height / 8) - 1) * 8;
		
		FlxG.overlap(_fruit, _snakeBody, randomizeFruitPosition);
	}
	
	private function updateScore(NewText: String):Void{
		_scoreText.text = NewText;
	}
}