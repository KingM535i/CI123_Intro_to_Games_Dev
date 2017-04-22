#include "SFEvent.h"

/**
 * Effectively wraps an SDL_Event in our custom event type.
 */
SFEvent::SFEvent(const SDL_Event & event) {
  switch (event.type) {
  case SDL_QUIT:
    code = SFEVENT_QUIT;
    break;
  case SDL_USEREVENT:
    code = SFEVENT_UPDATE;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym) {
    case SDLK_LEFT:
      code = SFEVENT_PLAYER_LEFT;
      break;
    case SDLK_RIGHT:
      code = SFEVENT_PLAYER_RIGHT;
      break;

      // Code added for player up & down movement. Converts keyboard arrow key inputs to events - MK

      case SDLK_UP:
      code = SFEVENT_PLAYER_UP;
      break;
      case SDLK_DOWN:
      code = SFEVENT_PLAYER_DOWN;
      break;

      // ^^

      // Code commented out to remove firing of bullets - MK

      /**
    case SDLK_SPACE:
      code = SFEVENT_FIRE;
      break;
      */

      //^^

    case SDLK_q:
      code = SFEVENT_QUIT;
      break;
    }
    break;
  default:
    code = SFEVENT_NULL;
    break;
  }
}


SFEVENT SFEvent::GetCode() {
  return code;
}
