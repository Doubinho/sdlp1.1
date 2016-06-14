#pragma once
#include <functional>
#include <SDL.h>
#include <vector>
#include <unordered_map>

using namespace std;

//���п�ע���¼���Ļ���
class EventDispatcher
{
public:
	virtual ~EventDispatcher();
	void addEventListener(SDL_EventType type, function<void(SDL_Event)>);
	void removeEventListeners(SDL_EventType type);
	void removeAllEvents();
	unordered_multimap<SDL_EventType, size_t> event_indexs;
};

