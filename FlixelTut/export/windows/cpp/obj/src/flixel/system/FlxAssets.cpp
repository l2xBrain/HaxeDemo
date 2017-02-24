#include <hxcpp.h>

#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_system_FlxAssets
#include <flixel/system/FlxAssets.h>
#endif
#ifndef INCLUDED_flixel_system_frontEnds_SoundFrontEnd
#include <flixel/system/frontEnds/SoundFrontEnd.h>
#endif
#ifndef INCLUDED_openfl__legacy_AssetType
#include <openfl/_legacy/AssetType.h>
#endif
#ifndef INCLUDED_openfl__legacy_Assets
#include <openfl/_legacy/Assets.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_BitmapData
#include <openfl/_legacy/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_Graphics
#include <openfl/_legacy/display/Graphics.h>
#endif
#ifndef INCLUDED_openfl__legacy_display_IBitmapDrawable
#include <openfl/_legacy/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_EventDispatcher
#include <openfl/_legacy/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_events_IEventDispatcher
#include <openfl/_legacy/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl__legacy_media_Sound
#include <openfl/_legacy/media/Sound.h>
#endif
namespace flixel{
namespace system{

Void FlxAssets_obj::__construct()
{
	return null();
}

//FlxAssets_obj::~FlxAssets_obj() { }

Dynamic FlxAssets_obj::__CreateEmpty() { return  new FlxAssets_obj; }
hx::ObjectPtr< FlxAssets_obj > FlxAssets_obj::__new()
{  hx::ObjectPtr< FlxAssets_obj > result = new FlxAssets_obj();
	result->__construct();
	return result;}

Dynamic FlxAssets_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FlxAssets_obj > result = new FlxAssets_obj();
	result->__construct();
	return result;}

::String FlxAssets_obj::FONT_DEFAULT;

::String FlxAssets_obj::FONT_DEBUGGER;

Void FlxAssets_obj::drawLogo( ::openfl::_legacy::display::Graphics graph){
{
		HX_STACK_FRAME("flixel.system.FlxAssets","drawLogo",0xabec0035,"flixel.system.FlxAssets.drawLogo","flixel/system/FlxAssets.hx",97,0xd3ac1356)
		HX_STACK_ARG(graph,"graph")
		HX_STACK_LINE(99)
		graph->beginFill((int)47394,null());
		HX_STACK_LINE(100)
		graph->moveTo((int)50,(int)13);
		HX_STACK_LINE(101)
		graph->lineTo((int)51,(int)13);
		HX_STACK_LINE(102)
		graph->lineTo((int)87,(int)50);
		HX_STACK_LINE(103)
		graph->lineTo((int)87,(int)51);
		HX_STACK_LINE(104)
		graph->lineTo((int)51,(int)87);
		HX_STACK_LINE(105)
		graph->lineTo((int)50,(int)87);
		HX_STACK_LINE(106)
		graph->lineTo((int)13,(int)51);
		HX_STACK_LINE(107)
		graph->lineTo((int)13,(int)50);
		HX_STACK_LINE(108)
		graph->lineTo((int)50,(int)13);
		HX_STACK_LINE(109)
		graph->endFill();
		HX_STACK_LINE(112)
		graph->beginFill((int)16761138,null());
		HX_STACK_LINE(113)
		graph->moveTo((int)0,(int)0);
		HX_STACK_LINE(114)
		graph->lineTo((int)25,(int)0);
		HX_STACK_LINE(115)
		graph->lineTo((int)50,(int)13);
		HX_STACK_LINE(116)
		graph->lineTo((int)13,(int)50);
		HX_STACK_LINE(117)
		graph->lineTo((int)0,(int)25);
		HX_STACK_LINE(118)
		graph->lineTo((int)0,(int)0);
		HX_STACK_LINE(119)
		graph->endFill();
		HX_STACK_LINE(122)
		graph->beginFill((int)16066382,null());
		HX_STACK_LINE(123)
		graph->moveTo((int)100,(int)0);
		HX_STACK_LINE(124)
		graph->lineTo((int)75,(int)0);
		HX_STACK_LINE(125)
		graph->lineTo((int)51,(int)13);
		HX_STACK_LINE(126)
		graph->lineTo((int)87,(int)50);
		HX_STACK_LINE(127)
		graph->lineTo((int)100,(int)25);
		HX_STACK_LINE(128)
		graph->lineTo((int)100,(int)0);
		HX_STACK_LINE(129)
		graph->endFill();
		HX_STACK_LINE(132)
		graph->beginFill((int)3555839,null());
		HX_STACK_LINE(133)
		graph->moveTo((int)0,(int)100);
		HX_STACK_LINE(134)
		graph->lineTo((int)25,(int)100);
		HX_STACK_LINE(135)
		graph->lineTo((int)50,(int)87);
		HX_STACK_LINE(136)
		graph->lineTo((int)13,(int)51);
		HX_STACK_LINE(137)
		graph->lineTo((int)0,(int)75);
		HX_STACK_LINE(138)
		graph->lineTo((int)0,(int)100);
		HX_STACK_LINE(139)
		graph->endFill();
		HX_STACK_LINE(142)
		graph->beginFill((int)314875,null());
		HX_STACK_LINE(143)
		graph->moveTo((int)100,(int)100);
		HX_STACK_LINE(144)
		graph->lineTo((int)75,(int)100);
		HX_STACK_LINE(145)
		graph->lineTo((int)51,(int)87);
		HX_STACK_LINE(146)
		graph->lineTo((int)87,(int)51);
		HX_STACK_LINE(147)
		graph->lineTo((int)100,(int)75);
		HX_STACK_LINE(148)
		graph->lineTo((int)100,(int)100);
		HX_STACK_LINE(149)
		graph->endFill();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAssets_obj,drawLogo,(void))

::openfl::_legacy::display::BitmapData FlxAssets_obj::getBitmapData( ::String id){
	HX_STACK_FRAME("flixel.system.FlxAssets","getBitmapData",0x17128189,"flixel.system.FlxAssets.getBitmapData","flixel/system/FlxAssets.hx",153,0xd3ac1356)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(154)
	::openfl::_legacy::display::BitmapData bd = null();		HX_STACK_VAR(bd,"bd");
	HX_STACK_LINE(160)
	if (((bd == null()))){
		HX_STACK_LINE(161)
		::openfl::_legacy::display::BitmapData _g = ::openfl::_legacy::Assets_obj::getBitmapData(id,false);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(161)
		bd = _g;
	}
	HX_STACK_LINE(163)
	if (((bd == null()))){
	}
	HX_STACK_LINE(168)
	return bd;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAssets_obj,getBitmapData,return )

::openfl::_legacy::media::Sound FlxAssets_obj::getSound( ::String id){
	HX_STACK_FRAME("flixel.system.FlxAssets","getSound",0x306e52ff,"flixel.system.FlxAssets.getSound","flixel/system/FlxAssets.hx",173,0xd3ac1356)
	HX_STACK_ARG(id,"id")
	HX_STACK_LINE(174)
	::String extension = HX_CSTRING("");		HX_STACK_VAR(extension,"extension");
	HX_STACK_LINE(178)
	extension = HX_CSTRING(".ogg");
	HX_STACK_LINE(180)
	return ::openfl::_legacy::Assets_obj::getSound((id + extension),null());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FlxAssets_obj,getSound,return )

Void FlxAssets_obj::cacheSounds( ){
{
		HX_STACK_FRAME("flixel.system.FlxAssets","cacheSounds",0x35d449c0,"flixel.system.FlxAssets.cacheSounds","flixel/system/FlxAssets.hx",194,0xd3ac1356)
		HX_STACK_LINE(194)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(194)
		Array< ::String > _g1 = ::openfl::_legacy::Assets_obj::list(::openfl::_legacy::AssetType_obj::SOUND);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(194)
		while((true)){
			HX_STACK_LINE(194)
			if ((!(((_g < _g1->length))))){
				HX_STACK_LINE(194)
				break;
			}
			HX_STACK_LINE(194)
			::String id = _g1->__get(_g);		HX_STACK_VAR(id,"id");
			HX_STACK_LINE(194)
			++(_g);
			HX_STACK_LINE(196)
			::flixel::FlxG_obj::sound->cache(id);
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FlxAssets_obj,cacheSounds,(void))


FlxAssets_obj::FlxAssets_obj()
{
}

Dynamic FlxAssets_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"drawLogo") ) { return drawLogo_dyn(); }
		if (HX_FIELD_EQ(inName,"getSound") ) { return getSound_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"cacheSounds") ) { return cacheSounds_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"FONT_DEFAULT") ) { return FONT_DEFAULT; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"FONT_DEBUGGER") ) { return FONT_DEBUGGER; }
		if (HX_FIELD_EQ(inName,"getBitmapData") ) { return getBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FlxAssets_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"FONT_DEFAULT") ) { FONT_DEFAULT=inValue.Cast< ::String >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"FONT_DEBUGGER") ) { FONT_DEBUGGER=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FlxAssets_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FONT_DEFAULT"),
	HX_CSTRING("FONT_DEBUGGER"),
	HX_CSTRING("drawLogo"),
	HX_CSTRING("getBitmapData"),
	HX_CSTRING("getSound"),
	HX_CSTRING("cacheSounds"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FlxAssets_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FlxAssets_obj::FONT_DEFAULT,"FONT_DEFAULT");
	HX_MARK_MEMBER_NAME(FlxAssets_obj::FONT_DEBUGGER,"FONT_DEBUGGER");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::FONT_DEFAULT,"FONT_DEFAULT");
	HX_VISIT_MEMBER_NAME(FlxAssets_obj::FONT_DEBUGGER,"FONT_DEBUGGER");
};

#endif

Class FlxAssets_obj::__mClass;

void FlxAssets_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flixel.system.FlxAssets"), hx::TCanCast< FlxAssets_obj> ,sStaticFields,sMemberFields,
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

void FlxAssets_obj::__boot()
{
	FONT_DEFAULT= HX_CSTRING("Nokia Cellphone FC Small");
	FONT_DEBUGGER= HX_CSTRING("Arial");
}

} // end namespace flixel
} // end namespace system
