#include <hxcpp.h>

#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_addons_editors_tiled_TiledMap
#include <flixel/addons/editors/tiled/TiledMap.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",16,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(23)
	this->_health = (int)3;
	HX_STACK_LINE(22)
	this->_money = (int)0;
	HX_STACK_LINE(16)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",28,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(29)
		::flixel::addons::editors::tiled::TiledMap _g = ::flixel::addons::editors::tiled::TiledMap_obj::__new(HX_CSTRING("assets/data/gameTile.tmx"));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		this->_map = _g;
		HX_STACK_LINE(30)
		::flixel::tile::FlxTilemap _g1 = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(30)
		this->_mWalls = _g1;
		HX_STACK_LINE(37)
		::Player _g2 = ::Player_obj::__new((int)20,(int)20);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(37)
		this->_player = _g2;
		HX_STACK_LINE(38)
		this->add(this->_player);
		HX_STACK_LINE(39)
		::HUD _g3 = ::HUD_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(39)
		this->_hud = _g3;
		HX_STACK_LINE(40)
		this->add(this->_hud);
		HX_STACK_LINE(41)
		this->super::create();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",50,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(50)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",58,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(58)
		this->super::update();
	}
return null();
}



PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(_player,"_player");
	HX_MARK_MEMBER_NAME(_map,"_map");
	HX_MARK_MEMBER_NAME(_mWalls,"_mWalls");
	HX_MARK_MEMBER_NAME(_hud,"_hud");
	HX_MARK_MEMBER_NAME(_money,"_money");
	HX_MARK_MEMBER_NAME(_health,"_health");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_player,"_player");
	HX_VISIT_MEMBER_NAME(_map,"_map");
	HX_VISIT_MEMBER_NAME(_mWalls,"_mWalls");
	HX_VISIT_MEMBER_NAME(_hud,"_hud");
	HX_VISIT_MEMBER_NAME(_money,"_money");
	HX_VISIT_MEMBER_NAME(_health,"_health");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { return _map; }
		if (HX_FIELD_EQ(inName,"_hud") ) { return _hud; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_money") ) { return _money; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { return _player; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { return _mWalls; }
		if (HX_FIELD_EQ(inName,"_health") ) { return _health; }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"_map") ) { _map=inValue.Cast< ::flixel::addons::editors::tiled::TiledMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_hud") ) { _hud=inValue.Cast< ::HUD >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"_money") ) { _money=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_player") ) { _player=inValue.Cast< ::Player >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_mWalls") ) { _mWalls=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_health") ) { _health=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_player"));
	outFields->push(HX_CSTRING("_map"));
	outFields->push(HX_CSTRING("_mWalls"));
	outFields->push(HX_CSTRING("_hud"));
	outFields->push(HX_CSTRING("_money"));
	outFields->push(HX_CSTRING("_health"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,_player),HX_CSTRING("_player")},
	{hx::fsObject /*::flixel::addons::editors::tiled::TiledMap*/ ,(int)offsetof(PlayState_obj,_map),HX_CSTRING("_map")},
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,_mWalls),HX_CSTRING("_mWalls")},
	{hx::fsObject /*::HUD*/ ,(int)offsetof(PlayState_obj,_hud),HX_CSTRING("_hud")},
	{hx::fsInt,(int)offsetof(PlayState_obj,_money),HX_CSTRING("_money")},
	{hx::fsInt,(int)offsetof(PlayState_obj,_health),HX_CSTRING("_health")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_player"),
	HX_CSTRING("_map"),
	HX_CSTRING("_mWalls"),
	HX_CSTRING("_hud"),
	HX_CSTRING("_money"),
	HX_CSTRING("_health"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PlayState_obj::__boot()
{
}

