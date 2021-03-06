#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <deque>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "ZE_error.h"
#include "ZE_Sprite.h"
#include "ZE_EventManager.h"
#include "ZE_Controller.h"
#include "ZE_Fraps.h"
#include "ZE_Font.h"
#include "ZE_EngineGlobalState.h"

using namespace std;

//[Global]ZE版本号
extern string ZE_version;
//[Global]引擎全局状态变量
extern unique_ptr<EngineGlobalState> GlobalState;

////[Global]保存SDL窗体的指针
//extern SDL_Window* g_ZE_Window;
////[Global]保存SDL主Surface的指针
//extern SDL_Surface* g_ZE_MainSurface;
////[Global]到现在也不知道这玩意到底该叫什么，就叫渲染器好了，这是主渲染器，绑定到主window
//extern SDL_Renderer* g_ZE_MainRenderer;
////[Global]stage对象，唯一
//extern Sprite ZE_stage;
////[Global]error对象(应该是唯一，其它类就算有也是private)
//extern Error ZE_error;
////[Global]事件处理器对象，唯一
//extern EventManager ZE_eventHandler;
////[Global]退出主循环的判定变量
//extern bool ZE_QUIT_MAIN_LOOP;
////[Global]保存所有的手柄指针
//extern deque<unique_ptr<Controller>> ZE_Controllers;
////[Global]系统默认字体
//extern shared_ptr<Font> defaultFont;


//颜色结构体，也就设置舞台颜色的时候用用
struct Color
{
	int red;
	int green;
	int blue;
};

//主Game类，用户应继承此类并重写MainLoop和Close方法，然后将一个对象的指针传递给start方法
class Game
{
public:
	virtual void MainLoop() {};
	virtual void Close() {};
};

//头文件中声明类，cpp中定义类，全都一样
//本文件是ZE的核心类，几乎所有其它类的对象都在此声明
//使用时，继承本类并重载Draw()方法，将绘图代码写在Draw方法中
class ZeroEngine
{
public:
	//舞台颜色，默认为黑
	Color stageColor = { 0, 0, 0 };
	//初始化方法，使用ZE前必须调用此方法
	//该方法调用了本类中的其它两个方法，分别初始化了外部库SDL和SDL_IMAGE
	//该方法会返回一个bool值，若所有模块初始化成功则返回true，否则返回false
	//外部库的报错写在对应方法里
	bool Init(string, int, int, bool, std::string defaultFontFile = "data/ttf/SourceHanSansSC-Normal.otf");
	//该方法是ZE的主循环方法，目前是暂用版
	void Start(Game*);

private:
	//最后渲染在舞台上，显示一些监视变量
	Fraps fraps;
	//SDL的初始化方法，该方法的三个参数分别是窗口标题、窗口宽度、窗口高度
	bool Init_SDL(string, int, int);
	//初始化了SDL_IMAGE第三方库
	bool Init_SDL_Image(bool);
	//初始化了SDL_TTF第三方库
	bool Init_SDL_ttf();
	bool Init_SDL_Mixer();
	//清理方法，安全的关闭SDL并退出程序
	void Close();
	//用户的游戏对象
	Game* maingame;
};