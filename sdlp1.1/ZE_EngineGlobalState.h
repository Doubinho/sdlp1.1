#pragma once

#include <memory>
#include <atomic>
#include <SDL.h>
#include "ZE_Sprite.h"
#include "ZE_error.h"
#include "ZE_EventManager.h"
#include "ZE_Controller.h"
#include "ZE_Font.h"

// �����ȫ��״̬������
// ��������ȫ�ֱ����Խ�����������鹹˳������
class EngineGlobalState
{
public:
	EngineGlobalState();
	~EngineGlobalState();

	//[Global]����SDL�����ָ��
	SDL_Window* g_ZE_Window{ NULL };
	//[Global]����SDL��Surface��ָ��
	SDL_Surface* g_ZE_MainSurface{ NULL };
	//[Global]������Ҳ��֪�������⵽�׸ý�ʲô���ͽ���Ⱦ�����ˣ���������Ⱦ�����󶨵���window
	SDL_Renderer* g_ZE_MainRenderer{ NULL };
	//[Global]stage����Ψһ
	unique_ptr<Sprite> ZE_stage;
	//[Global]error����(Ӧ����Ψһ�������������Ҳ��private)
	unique_ptr<Error> ZE_error;
	//[Global]�¼�����������Ψһ
	unique_ptr<EventManager> ZE_eventHandler;
	//[Global]�˳���ѭ�����ж�����
	atomic_bool ZE_QUIT_MAIN_LOOP{ false };
	//[Global]�������е��ֱ�ָ��
	deque<unique_ptr<Controller>> ZE_Controllers;
	//[Global]ϵͳĬ������
	shared_ptr<Font> defaultFont;
};

