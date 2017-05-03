#include "SFApp.h"

    // Functions for random number generation - MK //
    int SFApp::randomNumberX() {

    srand(time(NULL));
    SDL_Delay(250);

    int x = (rand() % 640);

    return x;
    }

    int SFApp::randomNumberY() {

    srand(time(NULL));
    SDL_Delay(250);

    int y = (rand() % 480);

    }
    // ^^

SFApp::SFApp(std::shared_ptr<SFWindow> window) : fire(0), is_running(true), sf_window(window) {
  int canvas_w, canvas_h;
  SDL_GetRendererOutputSize(sf_window->getRenderer(), &canvas_w, &canvas_h);



  app_box = make_shared<SFBoundingBox>(Vector2(canvas_w, canvas_h), canvas_w, canvas_h);
  player  = make_shared<SFAsset>(SFASSET_PLAYER, sf_window);

  // Original code to position player - MK //
  //auto player_pos = Point2(canvas_w/2, 22);

  // Modified code to randomly position player - MK //
  auto player_pos = Point2(randomNumberX(), randomNumberY());
  player->SetPosition(player_pos);

  const int number_of_aliens = 10;
  for(int i=0; i<number_of_aliens; i++) {
    // place an alien at width/number_of_aliens * i
    auto alien = make_shared<SFAsset>(SFASSET_ALIEN, sf_window);

    // Original code to position aliens - MK //
    // auto pos   = Point2((canvas_w/number_of_aliens) * i, 200.0f);

    // Modified code to randomly position aliens - MK //

    auto pos   = Point2(randomNumberX(), randomNumberY());

    // ^^

    alien->SetPosition(pos);
    aliens.push_back(alien);
  }

  // Code modified to increase number of coins from 1 to 3 - MK //
  const int number_of_coins = 3;

  for(int i=0; i < number_of_coins; i++) {

  auto coin = make_shared<SFAsset>(SFASSET_COIN, sf_window);

  // Original code to position coins - MK //
  // auto pos  = Point2((canvas_w/4), 100);

  // Modified code to randomly position coins - MK //
  auto pos  = Point2(randomNumberX(), randomNumberY());
  coin->SetPosition(pos);
  coins.push_back(coin);
  }
}



SFApp::~SFApp() {
}

/**
 * Handle all events that come from SDL.
 * These are timer or keyboard events.
 */
void SFApp::OnEvent(SFEvent& event) {
  SFEVENT the_event = event.GetCode();
  switch (the_event) {
  case SFEVENT_QUIT:
    is_running = false;
    break;
  case SFEVENT_UPDATE:
    OnUpdateWorld();
    OnRender();
    break;
  case SFEVENT_PLAYER_LEFT:
    player->GoWest();
    break;
  case SFEVENT_PLAYER_RIGHT:
    player->GoEast();
    break;

    // Code added for player up & down movement - MK //

    case SFEVENT_PLAYER_UP:
    player->GoNorth();
    break;
    case SFEVENT_PLAYER_DOWN:
    player->GoSouth();
    break;

    // ^^

    // Code commented out to remove firing of bullets - MK //

    /**
    case SFEVENT_FIRE:
    fire ++;
    FireProjectile();
    break;
    */

    // ^^
  }
}

int SFApp::OnExecute() {
  // Execute the app
  SDL_Event event;
  while (SDL_WaitEvent(&event) && is_running) {
    // wrap an SDL_Event with our SFEvent
    SFEvent sfevent((const SDL_Event) event);
    // handle our SFEvent
    OnEvent(sfevent);
  }
}

void SFApp::OnUpdateWorld() {

  // Commented out to remove firing of bullets - MK //
  // Update projectile positions
  /**
    for(auto p: projectiles) {
    p->GoNorth();
  }
  */

  // ^^

  // Commented out to stop coins moving off screen - MK //

  /**
  for(auto c: coins) {
    c->GoNorth();
  }
  */

  // ^^

  // Update enemy positions
  for(auto a : aliens) {
    // do something here
  }

  // This detects collisions between bullets & aliens. Commented out to remove firing of bullets - MK //
  // Detect collisions
  /**
  for(auto p : projectiles) {
    for(auto a : aliens) {
      if(p->CollidesWith(a)) {
        p->HandleCollision();
        a->HandleCollision();
      }
    }
  }
  */

  // ^^

  // remove dead aliens (the long way)
  list<shared_ptr<SFAsset>> tmp;
  for(auto a : aliens) {
    if(a->IsAlive()) {
      tmp.push_back(a);
    }
  }
  aliens.clear();
  aliens = list<shared_ptr<SFAsset>>(tmp);
}

void SFApp::OnRender() {
  SDL_RenderClear(sf_window->getRenderer());

  // draw the player
  player->OnRender();


  // Renders bullets. Commented out to remove firing of bullets - MK //

  /**
  for(auto p: projectiles) {
    if(p->IsAlive()) {p->OnRender();}
  }
  */

  // ^^

  for(auto a: aliens) {
    if(a->IsAlive()) {a->OnRender();}
  }

  for(auto c: coins) {
    c->OnRender();
  }

  // Switch the off-screen buffer to be on-screen
  SDL_RenderPresent(sf_window->getRenderer());
}

    // This function spawns bullets at the player position. Commented out to remove firing of bullets - MK //

    /**
void SFApp::FireProjectile() {
  auto pb = make_shared<SFAsset>(SFASSET_PROJECTILE, sf_window);
  auto v  = player->GetPosition();
  pb->SetPosition(v);
  projectiles.push_back(pb);
}
*/

    // ^^
