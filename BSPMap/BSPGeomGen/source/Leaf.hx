package ;

import openfl.geom.Rectangle;
import flixel.FlxG;
import flixel.util.FlxRandom;
import flixel.util.FlxPoint;
import openfl.geom.Rectangle;
/**
 * 叶子节点
 * @author AlexanderBrain
 */
class Leaf
{
	// 定义最小和最大的模块size
	public static inline var MIN_SIZE = 6;
	public static inline var MAX_SIZE = 24;
	// 定义地图的坐标和高宽
	public var x:Int;
	public var y:Int;
	public var width:Int;
	public var height:Int;
	// 定义子节点
	public var leftChild:Leaf;
	public var rightChild:Leaf;
	// 定义叶子节点的位置和高宽
	public var room:Rectangle;
	// 
	public var hallways:Array<Rectangle>;
	

	public function new(x:Int, y:Int, width:Int, height:Int) 
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	
	public function split():Bool {
		// Split leaf into 2 children
		if (leftChild != null || rightChild != null)
			return false; // Already split

		// Determine split direction
		// If width >25% larger than height, split vertically
		// Else if height >25% larger than width, split horizontally
		// Else split randomly
		// 随机的取得false或者true, 应对高和宽差不多的情况
		var splitH:Bool = FlxRandom.floatRanged(0, 1) > 0.5;

		if (width > height && height / width >= 0.05)
			splitH = false;
		else if (height > width && width / height >= 0.05)
			splitH = true;

		var max = (splitH ? height : width) - MIN_SIZE; // determine the maximum height or width
		if (max <= MIN_SIZE)
			return false; // the area is too small to split any more...

		// Where to split(在哪个位置分?)
		var split = Std.int(FlxRandom.floatRanged(MIN_SIZE, max)); // determine where we're going to split

		// Create children based on split direction
		if (splitH)
		{
			leftChild = new Leaf(x, y, width, split);
			rightChild = new Leaf(x, y + split, width, height - split);
		}
		else
		{
			leftChild = new Leaf(x, y, split, height);
			rightChild = new Leaf(x + split, y, width - split, height);
		}

		return true;
	}
	/**
	 * 相当于room的set方法, 给叶子节点分配区域
	 */
	public function createRooms():Void {
		// Generate all rooms and hallways in this leaf
		if (leftChild != null || rightChild != null) {
			if (leftChild != null) {
				leftChild.createRooms();
			}
			if (rightChild != null) {
				rightChild.createRooms();
			}
			if (leftChild != null && rightChild != null) {
				// 但是一个父节点的时候，进行连接
				createHall(leftChild.getRooms(), rightChild.getRooms());
			}
		} else {
			// 直到是叶子节点的情况下，分配room空间
			var roomSize = new FlxPoint(
				FlxRandom.floatRanged(3, width - 2),
				FlxRandom.floatRanged(3, height - 2)
			);
			var roomPos = new FlxPoint(
				FlxRandom.floatRanged(1, width - roomSize.x - 1),
				FlxRandom.floatRanged(1, width - roomSize.y - 1)
			);
			
			room = new Rectangle(x + roomPos.x, y + roomPos.y, roomSize.x, roomSize.y);
		}
	}
	/**
	 * 获取叶子节点的空间 
	 */
	public function getRooms():Rectangle {
		// 只有是叶子节点的情况下room才有值，不是叶子节点的话room为null,那么一定会有子节点.
		if (room != null) {
			return room;
		} else {
			var lRoom:Rectangle = null;
			var rRoom:Rectangle = null;
			if (leftChild != null) {
				lRoom = leftChild.getRooms();
			}
			if (rightChild != null) {
				rRoom = rightChild.getRooms();
			}
			if (lRoom == null && rRoom == null) {
				return null;
			} else if (lRoom == null) {
				return rRoom;
			} else if (rRoom == null) {
				return lRoom;
			} else if (FlxRandom.float() > 0.5) {
				return lRoom;
			} else {
				return rRoom;
			}
		}
	}
	/**
	 * 呈现的是子节点，但不是子节点。而是根据父节点随机的选择一块子节点连接
	 * @param	left
	 * @param	right
	 */
	public function createHall(left:Rectangle, right:Rectangle):Void {
		hallways = [];
		// 随机取得两个叶子空间中的点
		var point1 = FlxPoint.get(
			FlxRandom.floatRanged(left.left + 1, left.right - 2),
			FlxRandom.floatRanged(left.top + 1, left.bottom - 2)
		);
		var point2 = FlxPoint.get(
			FlxRandom.floatRanged(right.left + 1, right.right - 2),
			FlxRandom.floatRanged(right.top + 1, right.bottom - 2)
		);
		
		// 两个叶子节点中的距离
		var w = point2.x - point1.x;
		var h = point2.y - point1.y;
		
		if (w > 0) {
			if (h > 0) {
				// 这种情况对应的是右边的图形在左面图形的右上方, 那就有两种连接的方法
				if (FlxRandom.floatRanged(0, 1) > 0.5) {
					hallways.push(new Rectangle(point1.x, point1.y, Math.abs(w), 1));
					hallways.push(new Rectangle(point2.x, point1.y, 1, Math.abs(h)));
				} else {
					hallways.push(new Rectangle(point2.x, point2.y, 1, Math.abs(h)));
					hallways.push(new Rectangle(point1.x, point1.y, Math.abs(w), 1));
				}
			} else if (h < 0) {
				// 对应的情况是右边的图形在左边图形的左下方，也有两种连发
				if (FlxRandom.floatRanged(0, 1) > 0.5) {
					hallways.push(new Rectangle(point1.x, point1.y, Math.abs(w), 1));
					hallways.push(new Rectangle(point2.x, point1.y, 1, Math.abs(h)));
				} else {
					hallways.push(new Rectangle(point1.x, point1.y, 1, Math.abs(h)));
					hallways.push(new Rectangle(point1.x, point2.y, Math.abs(w), 1));
				}
			} else {
				// 对应的情况是右边的图像在左边图形的正右方。
				hallways.push(new Rectangle(point1.x, point1.y, Math.abs(w), 1));
			}
		} else if (w < 0) {
			if (h > 0) {
				// 对应的情况是左边的图形在右边图像的右下方, 可以有两种的连接的方法
				if (FlxRandom.floatRanged(0, 1) > 0.5) {
					hallways.push(new Rectangle(point2.x, point2.y, Math.abs(w), 1));
					hallways.push(new Rectangle(point1.x, point2.y, 1, Math.abs(h)));
				} else {
					hallways.push(new Rectangle(point2.x, point2.y, 1, Math.abs(h)));
					hallways.push(new Rectangle(point2.x, point1.y, Math.abs(w), 1));
				}
				
			}else if (h < 0) {
				// 对应的情况是左边的图形在右边图形的右上方， 可以有两种链接的方法
				if (FlxRandom.floatRanged(0, 1) > 0.5) {
					hallways.push(new Rectangle(point2.x, point2.y, Math.abs(w), 1));
					hallways.push(new Rectangle(point1.x, point2.y, 1, Math.abs(h)));
				} else {
					hallways.push(new Rectangle(point2.x, point1.y, 1, Math.abs(h)));
					hallways.push(new Rectangle(point2.x, point1.y, Math.abs(w), 1));
				}
			} else {
				// 对应的情况是 左边的图像在右边图像的正右方
				hallways.push(new Rectangle(point2.x, point2.y, Math.abs(2), 1));
			}
		} else {
			if (h > 0) {
				// 对应的情况是右边的图形在左边图形的正上方
				hallways.push(new Rectangle(point2.x, point2.y, 1, Math.abs(h)));
			} else if (h < 0) {
				// 对应的情况是右边图形在左边图形的正下方
				hallways.push(new Rectangle(point1.x, point1.y, 1, Math.abs(h)));
			}
		}
		
	}
	
}