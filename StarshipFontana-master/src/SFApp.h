#ifndef SFAPP_H
#define SFAPP_H

#include <memory>   // Pull in std::shared_ptr
#include <iostream> // Pull in std::cerr, std::endl
#include <list>     // Pull in list
#include <sstream>

// Included for random number generation - MK //
#include <ctime>

using namespace std;

#include "SFCommon.h"
#include "SFEvent.h"
#include "SFAsset.h"

/**
 * Represents the StarshipFontana application.  It has responsibilities for
 * * Creating and destroying the app window
 * * Processing game events
 */
class SFApp {
public:
  SFApp(std::shared_ptr<SFWindow>);
  virtual ~SFApp();
  void    OnEvent(SFEvent &);
  int     OnExecute();
  void    OnUpdateWorld();
  void    OnRender();

  // Functions for random number generation - MK //
  int randomNumberX();
  int randomNumberY();

  // Commented out to remove firing of bullets - MK //
  //void    FireProjectile();
  // ^^

private:
  bool                    is_running;

  shared_ptr<SFWindow>       sf_window;

  shared_ptr<SFAsset>        player;
  shared_ptr<SFBoundingBox>  app_box;

  // Commented out to remove firing of bullets - MK //
  //list<shared_ptr<SFAsset> > projectiles;
  // ^^

  list<shared_ptr<SFAsset> > aliens;
  list<shared_ptr<SFAsset> > coins;

  int fire;

};
#endif
