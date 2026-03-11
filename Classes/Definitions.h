#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define TRANSITION_TIME 0.5f

namespace defs {
	class PauseableProtocol {
		virtual void setPaused(bool paused) = 0;
		virtual bool isPaused() = 0;
	};

	class PlayableProtocol : public PauseableProtocol {
		virtual void play() = 0;
		virtual void stop() = 0;
	};
}

#endif //!__DEFINITIONS_H__