#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

/*
Single header for all const variables, macros, TINY interfaces (delegates, protocols, services) and typedefs
! NO BIG HEADERS HERE ! ~~Fast compiling~~ <3

btw compile stats (default flags)
Cocos2d-x 3.17.2:
First - 30sec

Axmol 2.1.5:
First - 5 min 10 sec 0_0
*/

#define TRANSITION_TIME 0.5f

namespace defs {
	class PauseableProtocol {
	public:
		virtual void setPaused(bool paused) = 0;
		virtual bool isPaused() = 0;
	};

	class PlayableProtocol : public PauseableProtocol {
	public:
		virtual void play() = 0;
		virtual void stop() = 0;
	};
}

#endif //!__DEFINITIONS_H__