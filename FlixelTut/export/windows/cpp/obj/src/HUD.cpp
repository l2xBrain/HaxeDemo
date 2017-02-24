#include <hxcpp.h>

#ifndef INCLUDED_HUD
#include <HUD.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_flixel_util_FlxSpriteUtil
#include <flixel/util/FlxSpriteUtil.h>
#endif

Void HUD_obj::__construct()
{
HX_STACK_FRAME("HUD","new",0xf45a2509,"HUD.new","HUD.hx",23,0xe7d70e87)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(24)
	super::__construct(null());
	HX_STACK_LINE(25)
	::flixel::FlxSprite _g = ::flixel::FlxSprite_obj::__new(null(),null(),null())->makeGraphic(::flixel::FlxG_obj::width,(int)20,(int)-16777216,null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(25)
	this->_sprBack = _g;
	HX_STACK_LINE(26)
	::flixel::util::FlxSpriteUtil_obj::drawRect(this->_sprBack,(int)0,(int)19,::flixel::FlxG_obj::width,(int)1,(int)-1,null(),null(),null());
	HX_STACK_LINE(27)
	::flixel::text::FlxText _g1 = ::flixel::text::FlxText_obj::__new((int)16,(int)2,::flixel::FlxG_obj::width,HX_CSTRING("3 / 3"),(int)8,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(27)
	this->_txtHealth = _g1;
	HX_STACK_LINE(29)
	::flixel::text::FlxText _g2 = ::flixel::text::FlxText_obj::__new((int)0,(int)2,::flixel::FlxG_obj::width,HX_CSTRING("0"),(int)8,null());		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(29)
	this->_txtMoney = _g2;
	HX_STACK_LINE(31)
	Float _g3 = this->_txtHealth->get_height();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(31)
	Float _g4 = (Float(_g3) / Float((int)2));		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(31)
	Float _g5 = (this->_txtHealth->y + _g4);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(31)
	Float _g6 = (_g5 - (int)4);		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(31)
	::flixel::FlxSprite _g7 = ::flixel::FlxSprite_obj::__new((int)4,_g6,HX_CSTRING("assets/images/health.png"));		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(31)
	this->_sprHealth = _g7;
	HX_STACK_LINE(32)
	Float _g8 = this->_txtMoney->get_height();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(32)
	Float _g9 = (Float(_g8) / Float((int)2));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(32)
	Float _g10 = (this->_txtMoney->y + _g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(32)
	Float _g11 = (_g10 - (int)4);		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(32)
	::flixel::FlxSprite _g12 = ::flixel::FlxSprite_obj::__new((::flixel::FlxG_obj::width - (int)12),_g11,HX_CSTRING("assets/images/health.png"));		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(32)
	this->_sprMoney = _g12;
	HX_STACK_LINE(33)
	this->_txtMoney->set_alignment(HX_CSTRING("right"));
	HX_STACK_LINE(34)
	Float _g13 = this->_txtMoney->get_width();		HX_STACK_VAR(_g13,"_g13");
	HX_STACK_LINE(34)
	Float _g14 = (this->_sprMoney->x - _g13);		HX_STACK_VAR(_g14,"_g14");
	HX_STACK_LINE(34)
	Float _g15 = (_g14 - (int)4);		HX_STACK_VAR(_g15,"_g15");
	HX_STACK_LINE(34)
	this->_txtMoney->set_x(_g15);
	HX_STACK_LINE(35)
	this->add(this->_sprBack);
	HX_STACK_LINE(36)
	this->add(this->_txtHealth);
	HX_STACK_LINE(37)
	this->add(this->_txtMoney);
	HX_STACK_LINE(38)
	this->add(this->_sprHealth);
	HX_STACK_LINE(39)
	this->add(this->_sprMoney);

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_1)
	Void run(::flixel::FlxSprite spr){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","HUD.hx",42,0xe7d70e87)
		HX_STACK_ARG(spr,"spr")
		{
			HX_STACK_LINE(42)
			spr->scrollFactor->set((int)0,(int)0);
		}
		return null();
	}
	HX_END_LOCAL_FUNC1((void))

	HX_STACK_LINE(41)
	this->forEach( Dynamic(new _Function_1_1()));
}
;
	return null();
}

//HUD_obj::~HUD_obj() { }

Dynamic HUD_obj::__CreateEmpty() { return  new HUD_obj; }
hx::ObjectPtr< HUD_obj > HUD_obj::__new()
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}

Dynamic HUD_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HUD_obj > result = new HUD_obj();
	result->__construct();
	return result;}


HUD_obj::HUD_obj()
{
}

void HUD_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HUD);
	HX_MARK_MEMBER_NAME(_sprBack,"_sprBack");
	HX_MARK_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_MARK_MEMBER_NAME(_txtHealth,"_txtHealth");
	HX_MARK_MEMBER_NAME(_sprMoney,"_sprMoney");
	HX_MARK_MEMBER_NAME(_sprHealth,"_sprHealth");
	::flixel::group::FlxTypedGroup_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void HUD_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(_sprBack,"_sprBack");
	HX_VISIT_MEMBER_NAME(_txtMoney,"_txtMoney");
	HX_VISIT_MEMBER_NAME(_txtHealth,"_txtHealth");
	HX_VISIT_MEMBER_NAME(_sprMoney,"_sprMoney");
	HX_VISIT_MEMBER_NAME(_sprHealth,"_sprHealth");
	::flixel::group::FlxTypedGroup_obj::__Visit(HX_VISIT_ARG);
}

Dynamic HUD_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_sprBack") ) { return _sprBack; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { return _txtMoney; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { return _sprMoney; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_txtHealth") ) { return _txtHealth; }
		if (HX_FIELD_EQ(inName,"_sprHealth") ) { return _sprHealth; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HUD_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 8:
		if (HX_FIELD_EQ(inName,"_sprBack") ) { _sprBack=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"_txtMoney") ) { _txtMoney=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprMoney") ) { _sprMoney=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"_txtHealth") ) { _txtHealth=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_sprHealth") ) { _sprHealth=inValue.Cast< ::flixel::FlxSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HUD_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("_sprBack"));
	outFields->push(HX_CSTRING("_txtMoney"));
	outFields->push(HX_CSTRING("_txtHealth"));
	outFields->push(HX_CSTRING("_sprMoney"));
	outFields->push(HX_CSTRING("_sprHealth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprBack),HX_CSTRING("_sprBack")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtMoney),HX_CSTRING("_txtMoney")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(HUD_obj,_txtHealth),HX_CSTRING("_txtHealth")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprMoney),HX_CSTRING("_sprMoney")},
	{hx::fsObject /*::flixel::FlxSprite*/ ,(int)offsetof(HUD_obj,_sprHealth),HX_CSTRING("_sprHealth")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("_sprBack"),
	HX_CSTRING("_txtMoney"),
	HX_CSTRING("_txtHealth"),
	HX_CSTRING("_sprMoney"),
	HX_CSTRING("_sprHealth"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HUD_obj::__mClass,"__mClass");
};

#endif

Class HUD_obj::__mClass;

void HUD_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("HUD"), hx::TCanCast< HUD_obj> ,sStaticFields,sMemberFields,
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

void HUD_obj::__boot()
{
}

