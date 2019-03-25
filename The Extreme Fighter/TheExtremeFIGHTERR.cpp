

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<cstdlib>
#include<vector>

using namespace std;
using namespace sf;

class Bullet
{
public:
    Sprite shape;

    Bullet(Texture *texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);

        this->shape.setScale(0.07f, 0.07f);

        this->shape.setPosition(pos);
    }

    ~Bullet() {}
};

class Bullet2
{
public:
    Sprite shape;

    Bullet2(Texture *texture, Vector2f pos)
    {
        this->shape.setTexture(*texture);

        this->shape.setScale(.5f, 70.f);

        //this->shape.setPosition(pos);
        this->shape.setPosition(0, 0);
    }

    ~Bullet2() {}
};


class Player
{
public:
    Sprite shape;
    Texture *texture;

    int HP;
    int HPMax;

    std::vector<Bullet> bullets;
    std::vector<Bullet2> bullets2;

    Player(Texture *texture)
    {
        this->HPMax = 15;
        this->HP = this->HPMax;

        this->texture = texture;
        this->shape.setTexture(*texture);

        this->shape.setScale(0.1f, 0.1f);
    }

    ~Player() {}

};



//For rock.png
class Enemy
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 2 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);
        this->shape.setScale(1.5f, 1.5f);
        this ->shape.setTextureRect(IntRect(0, 0, 70, 70));
        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy() {}
};




class Enemy2e
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy2e(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 2 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);
        this->shape.setScale(2.5f, 2.5f);
        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy2e() {}
};


//For enemy2.png
class Enemy2
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy2(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 3 + 1;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);
        this->shape.setScale(1.5f, 1.5f);
        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy2() {}
};


//enemy3(server.png)
class Enemy3
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy3(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 4 + 1;
        this->HP = this->HPMax;
        this->shape.setTexture(*texture);
        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy3() {}
};


class Enemy4
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemy4(Texture *texture, Vector2u windowSize)
    {
        this->HPMax = rand() % 5 + 4;
        this->HP = this->HPMax;

        this->shape.setTexture(*texture);
        this->shape.setScale(1.5f, 1.5f);
        this ->shape.setTextureRect(IntRect(0, 0, 70, 70));
        this->shape.setPosition(windowSize.x - this->shape.getGlobalBounds().width, rand()% (int)(windowSize.y - this->shape.getGlobalBounds().height));
    }

    ~Enemy4() {}
};


//For rock.png
class Enemyboss
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemyboss(Texture *texture, Vector2u windowSize)
    {

        this -> HPMax = 190;
        this->HP = this->HPMax;
        this->shape.setTexture(*texture);
        this->shape.setScale(.5f, .5f);
        this -> shape.setPosition(900, 300);
    }

    ~Enemyboss() {}
};


class Enemyboss2
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemyboss2(Texture *texture, Vector2u windowSize)
    {
        this->shape.setTexture(*texture);
        this->shape.setScale(.1f, .1f);
        this -> shape.rotate(270);
        this -> shape.setPosition(900, 300);
    }

    ~Enemyboss2() {}
};



class Enemyboss22
{
public:
    Sprite shape;

    int HP;
    int HPMax;
    Enemyboss22(Texture *texture, Vector2u windowSize)
    {

        this->shape.setTexture(*texture);

        this->shape.setScale(.1f, .1f);

        this -> shape.rotate(270);

        this -> shape.setPosition(900, 470);
    }

    ~Enemyboss22() {}
};

class Enemyboss3
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemyboss3(Texture *texture, Vector2u windowSize)
    {


        this->shape.setTexture(*texture);


        this->shape.setScale(5.5f, .2f);
        this -> shape.setPosition(1200, 0);

    }

    ~Enemyboss3() {}
};



class Enemyboss4
{
public:
    Sprite shape;

    int HP;
    int HPMax;

    Enemyboss4(Texture *texture, Vector2u windowSize)
    {


        this->shape.setTexture(*texture);


        this->shape.setScale(5.5f, .2f);
        //this -> shape.rotate(30);
        this -> shape.setPosition(700, 700);

    }

    ~Enemyboss4() {}
};





int main()
{
    srand(time(NULL));

    RenderWindow window(VideoMode(1200, 800), "THE Extreme Fighter", Style::Default);
    window.setFramerateLimit(200);


    Texture tnassa, tstation, tmoon, tlife;
    tnassa.loadFromFile("nassa.jpg");
    //tstation.loadFromFile("station.jpg");
    tstation.loadFromFile("sky5.jpg");
    tmoon.loadFromFile("dmmm.png");
    //enemies = server, enemy4, rock

    Texture enemyTexboss, enemyTexboss2, enemyTexboss22, enemyTexboss3, enemyTexboss4;

    enemyTexboss.loadFromFile("ss.png");
    enemyTexboss2.loadFromFile("fire1.png");
    enemyTexboss22.loadFromFile("fire1.png");
    enemyTexboss3.loadFromFile("fire1.png");
    enemyTexboss4.loadFromFile("fire1.png");
    //menu
    Texture smenu;
    smenu.loadFromFile("menu.jpg");
    Sprite menus;
    menus.scale(1.f, 1.1f);
    menus.setTexture(smenu);
    int mn=1;


    ///Sound
    SoundBuffer bf;
    bf.loadFromFile("gulimara.wav");

    Sound fire;
    fire.setBuffer(bf);
    fire.setVolume(30);


    Music music;
    music.openFromFile("tefibm3.ogg");
    music.play();
    music.setLoop(true);
    ///fonts
    Font f;
    f.loadFromFile("ALGER.TTF");

    ///TExt menu
    Text m;
    m.setFont(f);
    m.setString("THe Extreme Fighter");
    m.setCharacterSize(44);
    m.setPosition(350,200);

    //
    Text newgame;
    newgame.setFont(f);
    newgame.setString("Start Game");
    newgame.setFillColor(Color::White);
    newgame.setCharacterSize(34);
    newgame.setPosition(450,300);

    Text insta;
    insta.setFont(f);
    insta.setString("Instruction");
    insta.setFillColor(Color::White);
    insta.setCharacterSize(34);
    insta.setPosition(450,270);



    Sprite sstation(tstation), smoon(tmoon), snassa(tnassa), slife(tlife);

    //sstation.setPosition(0, 620);
    sstation.setPosition(0, 0);
    sstation.scale(1.6f, 1.6f);
    smoon.scale(.3f, .3f);
    smoon.setPosition(100, 100);
    snassa.setPosition(700, 620);
    slife.setPosition(400, 0);
    slife.scale(.2f, .2f);


    Clock clock;
    float dt = 0.f;
    float dtMultiplier = 62.5f, ktMultiplier = 62.5f;

    Clock cl;
    float tym;



    int hudai = 0;
//	Init text
    Font font;
    font.loadFromFile("SitkaB.ttc");

//	Init textures
    Texture playerTex;
    playerTex.loadFromFile("spaceship3.png");

    //enemies = server, enemy4, rock, ball.png, small_rock.png, trie.png

    Texture enemyTex, enemyTex2, enemyTex3, enemyTex2e, enemyTex4;
    //enemyTex.loadFromFile("enemy.png");
    //enemyTex.loadFromFile("server.png");
    enemyTex.loadFromFile("rock_small.png");
    enemyTex2.loadFromFile("enemy2.png");
    enemyTex2e.loadFromFile("ball.png");
    enemyTex3.loadFromFile("server.png");
    enemyTex4.loadFromFile("rock.png");


    Texture bulletTex, bulletTex2;
    bulletTex.loadFromFile("missileTex01.png");
    bulletTex2.loadFromFile("firebullet2.jpg");

//	UI init
//score
    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(Color::White);

    scoreText.setPosition(1000.f, 0.f);

    //gameover lekha
    Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(60);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(350, 350);
    gameOverText.setString("GAME OVER");

    //Press Enter to go to the Main Menu

    Text gameOverText1;
    gameOverText1.setFont(font);
    gameOverText1.setCharacterSize(30);
    gameOverText1.setFillColor(Color::Green);
    gameOverText1.setPosition(250, 450);
    gameOverText1.setString("Press Enter to go to the Main Menu");




//Player init
//life of player
    int score = 0;
    Player player(&playerTex);
    float shootTimer = 20.f;
    Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(20);
    hpText.setFillColor(Color::Green);

    //Enemy init
    float CreateEnemy = 0.f;
    std::vector<Enemy> enemies;
    std::vector<Enemy2> enemies2;
    std::vector<Enemy2e> enemies2e;
    std::vector<Enemy3> enemies3;
    std::vector<Enemy4> enemies4;
    std::vector<Enemyboss> enemiesboss;
    std::vector<Enemyboss2> enemiesboss2;
    std::vector<Enemyboss22> enemiesboss22;
    std::vector<Enemyboss3> enemiesboss3;
    std::vector<Enemyboss4> enemiesboss4;


    Text eHpText;
    eHpText.setFont(font);
    eHpText.setCharacterSize(30);
    eHpText.setFillColor(Color::White);


    Text sp;
    sp.setFont(font);
    sp.setCharacterSize(25);
    sp.setFillColor(Color::White);
    sp.setPosition(250, 700);
    sp.setString("Special Power is loading..\nTap the Mouse's Left Button + Up/Down arrow");


    Text rock;
    rock.setFont(font);
    rock.setCharacterSize(20);
    rock.setFillColor(Color::White);
    rock.setPosition(400, 0);
    rock.setString("Level : 1 - Stream of Rocks");



    Text snitch;
    snitch.setFont(font);
    snitch.setCharacterSize(20);
    snitch.setFillColor(Color::Yellow);
    snitch.setPosition(400, 0);
    snitch.setString("Level : 2 - The Xanthous Raiders");


    Text meteorite;
    meteorite.setFont(font);
    meteorite.setCharacterSize(20);
    meteorite.setFillColor(Color::Green);
    meteorite.setPosition(400, 0);
    meteorite.setString("Level : 3 - Dancing Meteorites");


    Text rival;
    rival.setFont(font);
    rival.setCharacterSize(20);
    rival.setFillColor(Color::White);
    rival.setPosition(400, 0);
    rival.setString("Level : 4 - The Speedy Rivals");

    Text throbbing;
    throbbing.setFont(font);
    throbbing.setCharacterSize(20);
    throbbing.setFillColor(Color::Red);
    throbbing.setPosition(400, 0);
    throbbing.setString("Level : 5 - Throbbing Rocks");


    Text khelahbe;
    khelahbe.setFont(font);
    khelahbe.setCharacterSize(34);
    khelahbe.setFillColor(Color::Red);
    khelahbe.setString("Level : Boss");
    khelahbe.setPosition(400.f, 0.f);

    Text aboutjalopy;
    aboutjalopy.setFont(font);
    aboutjalopy.setCharacterSize(18);
    aboutjalopy.setFillColor(Color::Red);
    aboutjalopy.setString("Control : Use Arrows to control the Jalopy.Click on the Left side of the Mouse for Shooting\nClick Right side of the mouse on Start Game");
    aboutjalopy.setPosition(100.f, 500.f);



    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        dt = clock.restart().asSeconds();
        Clock hp;
        float dp;
        dp = hp.getElapsedTime().asSeconds();


        if(mn==1)
        {
            player.HP=15;
            window.clear();
            window.draw(menus);
            window.draw(m);
            window.draw(newgame);
            window.draw(aboutjalopy);
           // window.draw(insta);
            if( (Mouse::getPosition().x >= 818 ) && (Mouse::getPosition().x <= 1025) && (Mouse::getPosition().y >= 493 ) && (Mouse::getPosition().y <= 518)  &&  (Mouse::isButtonPressed(Mouse::Right)) )
                mn=0;

           // std::cout<<Mouse::getPosition().x<<" "<<Mouse::getPosition().y<<endl;
        }



        if(mn == 0)
        {

            if (player.HP > 0 )// && score < 60)
            {


                //Player
                if (Keyboard::isKeyPressed(Keyboard::Up))
                    player.shape.move(0.f, -10.f * dt * dtMultiplier);
                if (Keyboard::isKeyPressed(Keyboard::Left))
                    player.shape.move(-10.f * dt * dtMultiplier, 0.f);
                if (Keyboard::isKeyPressed(Keyboard::Down))
                    player.shape.move(0.f, 10.f * dt * dtMultiplier);
                if (Keyboard::isKeyPressed(Keyboard::Right))
                    player.shape.move(10.f * dt * dtMultiplier, 0.f);

                //hpText.setPosition(player.shape.getPosition().x, player.shape.getPosition().y - hpText.getGlobalBounds().height);
                hpText.setPosition(800, 0); //position of jalopy's life
                hpText.setString("LIFE: " + std::to_string(player.HP));// + "/" + std::to_string(player.HPMax));


                //Collision with window
                if (player.shape.getPosition().x <= 0) //Left
                    player.shape.setPosition(0.f, player.shape.getPosition().y);
                if (player.shape.getPosition().x >= window.getSize().x - player.shape.getGlobalBounds().width) //Right
                    player.shape.setPosition(window.getSize().x - player.shape.getGlobalBounds().width, player.shape.getPosition().y);
                if (player.shape.getPosition().y <= 0) //Top
                    player.shape.setPosition(player.shape.getPosition().x, 0.f);
                if (player.shape.getPosition().y >= window.getSize().y - player.shape.getGlobalBounds().height) //Bottom
                    player.shape.setPosition(player.shape.getPosition().x, window.getSize().y - player.shape.getGlobalBounds().height);

//			Update Controls
                if (shootTimer < 15)
                    shootTimer += 1.f *dt * dtMultiplier;
                {
                    if((score >= 0 && score < 190) || (score > 220 && score <= 550))
                    {
                        if ((Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15) && score <= 550)// Shooting
                        {
                            fire.play();
                            player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                            shootTimer = 0; //reset timer
                        }
                    }

                }

                if(score >= 190 && score <= 220)
                {
                    if (Mouse::isButtonPressed(Mouse::Left) && shootTimer >= 15)// Shooting

                    {
                        player.bullets2.push_back(Bullet2(&bulletTex2, player.shape.getPosition()));
                        shootTimer = 0; //reset timer
                    }
                }



                if(score == 75 || score == 76 || score == 77 || score == 78 || score == 79 ||score == 80 || score == 81 || score == 82 || score == 83 || score == 84 || score == 85 || score == 150 || score == 151 || score == 152 || score == 153 || score == 154 || score == 155 || score == 156 || score == 157 || score == 158 || score == 159 || score == 160)
                {
                    if (Mouse::isButtonPressed(Mouse::Left) && ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::Up))) && shootTimer >= 0)// Shooting
                    {
                        // fire.play();
                        player.bullets.push_back(Bullet(&bulletTex, player.shape.getPosition()));
                        shootTimer = 0; //reset timer
                    }
                }

//			Bullets
                if(score < 60)
                {

                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet

//
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemies.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies[k].shape.getGlobalBounds()))
                            {
                                if (enemies[k].HP <= 1)
                                {
                                    score += enemies[k].HPMax;//increasing score
                                    enemies.erase(enemies.begin() + k); //delete enemies
                                }
                                else
                                    enemies[k].HP--;// Take down enemies

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy




                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow


                    if (CreateEnemy >= 25)
                    {
                        enemies.push_back(Enemy(&enemyTex, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }



                    for (size_t i = 0; i < enemies.size(); i++)
                    {
                        enemies[i].shape.move(-9.f * dt * dtMultiplier, 0.f);

                        //enemies[i].shape.move(-6.f * dt * dtMultiplier, 1.5f);
                        //enemies[i].shape.move(-6.f * dt * dtMultiplier, -.005f);
                        //enemies[i].shape.move(-1.f * dt * dtMultiplier, -2.f);


                        if (enemies[i].shape.getPosition().x <= 0 - enemies[i].shape.getGlobalBounds().width)
                        {
                            enemies.erase(enemies.begin() + i);
                            break;
                        }

                        if (enemies[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemies.erase(enemies.begin() + i);


                            {
                                player.HP--;  //Damaging the Jalopy
                                break;

                            }
                        }
                    }
                }

//2nd enemy loop starts

                if(score >= 60 && score < 120)
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet
                        //player.bullets[i].shape.rotate(.5);

//
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemies2.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies2[k].shape.getGlobalBounds()))
                            {
                                if (enemies2[k].HP <= 1)
                                {
                                    score += enemies2[k].HPMax;//increasing score
                                    enemies2.erase(enemies2.begin() + k); //delete enemies2
                                }
                                else
                                    enemies2[k].HP--;// Take down enemies

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemies2.push_back(Enemy2(&enemyTex2, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemies2.size(); i++)
                    {
                        enemies2[i].shape.move(-12.f * dt * dtMultiplier, 0.f);
                        enemies2[i].shape.rotate(.2);

                        if (enemies2[i].shape.getPosition().x <= 0 - enemies2[i].shape.getGlobalBounds().width)
                        {
                            enemies2.erase(enemies2.begin() + i);
                            break;
                        }

                        if (enemies2[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemies2.erase(enemies2.begin() + i);

                            player.HP--;  //Damaging the Jalopy
                            break;
                        }
                    }
                }

//2nd enemy loop end




//extra2enemy loop starts

                if(score >= 120 && score < 180)
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(30.f * dt * dtMultiplier, 0.f);//speed of bullet

//
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemies2e.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies2e[k].shape.getGlobalBounds()))
                            {
                                if (enemies2e[k].HP <= 1)
                                {
                                    score += enemies2e[k].HPMax;//increasing score
                                    enemies2e.erase(enemies2e.begin() + k); //delete enemies2e
                                }
                                else
                                    enemies2e[k].HP--;// Take down enemies

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemies2e.push_back(Enemy2e(&enemyTex2e, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemies2e.size(); i++)
                    {
                        //enemies2e[i].shape.move(-6.f * dt * dtMultiplier, 1.5f);
                        //enemies2e[i].shape.move(-6.f * dt * dtMultiplier, -.005f);
                        //enemies2e[i].shape.move(-1.f * dt * dtMultiplier, -2.f);

                        if(score % 2 == 0)
                        {
                            enemies2e[i].shape.move(-6.f * dt * dtMultiplier, 1.5f);
                            enemies2e[i].shape.move(-6.f * dt * dtMultiplier, -.005f);
                        }


                        if(score % 2 == 1)
                        {
                            enemies2e[i].shape.move(-6.f * dt * dtMultiplier, -.05f);
                            enemies2e[i].shape.move(-1.f * dt * dtMultiplier, -2.f);
                        }

                        if (enemies2e[i].shape.getPosition().x <= 0 - enemies2e[i].shape.getGlobalBounds().width)
                        {
                            enemies2e.erase(enemies2e.begin() + i);
                            break;
                        }

                        if (enemies2e[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemies2e.erase(enemies2e.begin() + i);

                            player.HP--;  //Damaging the Jalopy
                            break;
                        }
                    }
                }







//3rd enemy loop part 1 starts

                if(score >= 180 && score < 250) //|| (score > 30 && score < 1000))
                {

                    if(score >= 190 && score <= 220)
                    {
                        for (size_t i = 0; i < player.bullets2.size(); i++)
                        {
                            //Move
                            player.bullets2[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet


//
                            if (player.bullets2[i].shape.getPosition().x > window.getSize().x)
                            {
                                player.bullets2.erase(player.bullets2.begin() + i);
                                break;
                            }
                            //Enemy collision
                            for (size_t k = 0; k < enemies3.size(); k++)
                            {
                                if (player.bullets2[i].shape.getGlobalBounds().intersects(enemies3[k].shape.getGlobalBounds()))
                                {
                                    if (enemies3[k].HP <= 4)
                                    {
                                        score += enemies3[k].HPMax;//increasing score
                                        enemies3.erase(enemies3.begin() + k); //delete enemies3
                                    }
                                    else
                                        enemies3[k].HP = enemies3[k].HP - enemies3[k].HPMax;// Take down enemies

                                    player.bullets2.erase(player.bullets2.begin() + i);
                                    break;
                                }
                            }
                        }
                        //Enemy
                        if (CreateEnemy < 25)
                            CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                        if (CreateEnemy >= 25)
                        {
                            enemies3.push_back(Enemy3(&enemyTex3, window.getSize()));
                            CreateEnemy = 0;// reset timer
                        }

                        for (size_t i = 0; i < enemies3.size(); i++)
                        {
                            enemies3[i].shape.move(-9.f * dt * dtMultiplier, 0.f);



                            if (enemies3[i].shape.getPosition().x <= 0 - enemies3[i].shape.getGlobalBounds().width)
                            {
                                enemies3.erase(enemies3.begin() + i);
                                break;
                            }

                            if (enemies3[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                            {
                                enemies3.erase(enemies3.begin() + i);

                                player.HP--;  //Damaging the Jalopy
                                break;
                            }
                        }

                    }






                    else
                    {
                        for (size_t i = 0; i < player.bullets.size(); i++)
                        {
                            //Move
                            player.bullets[i].shape.move(40.f * dt * dtMultiplier, 0.f);//speed of bullet
                            player.bullets[i].shape.rotate(.1);

//
                            if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                            {
                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                            //Enemy collision
                            for (size_t k = 0; k < enemies3.size(); k++)
                            {
                                if (player.bullets[i].shape.getGlobalBounds().intersects(enemies3[k].shape.getGlobalBounds()))
                                {
                                    if (enemies3[k].HP <= 2)
                                    {
                                        score += enemies3[k].HPMax;//increasing score
                                        enemies3.erase(enemies3.begin() + k); //delete enemies3
                                    }
                                    else
                                    {
                                        enemies3[k].HP = enemies3[k].HP - 2;
                                        //enemies3[k].HP--;// Take down enemies

                                    }


                                    player.bullets.erase(player.bullets.begin() + i);
                                    break;
                                }
                            }
                        }
                        //Enemy
                        if (CreateEnemy < 25)
                            CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                        if (CreateEnemy >= 25)
                        {
                            enemies3.push_back(Enemy3(&enemyTex3, window.getSize()));
                            CreateEnemy = 0;// reset timer
                        }

                        for (size_t i = 0; i < enemies3.size(); i++)
                        {
                            enemies3[i].shape.move(-12.f * dt * dtMultiplier, 0.f);

                            if (enemies3[i].shape.getPosition().x <= 0 - enemies3[i].shape.getGlobalBounds().width)
                            {
                                enemies3.erase(enemies3.begin() + i);
                                break;
                            }

                            if (enemies3[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                            {
                                enemies3.erase(enemies3.begin() + i);

                                player.HP--;  //Damaging the Jalopy
                                break;
                            }
                        }
                    }

                }

//3rd enemy loop ends

//4th enemy loop starts


                if(score >= 250 && score< 360 )
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet
                        player.bullets[i].shape.rotate(.1);

//
                        if (player.bullets[i].shape.getPosition().x > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemies4.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemies4[k].shape.getGlobalBounds()))
                            {
                                if (enemies4[k].HP <= 2)
                                {
                                    score += enemies4[k].HPMax;//increasing score
                                    enemies4.erase(enemies4.begin() + k); //delete enemies4
                                }
                                else
                                    enemies4[k].HP = enemies4[k].HP - 1;// Take down enemies

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy



//			enemy grow

                    if (CreateEnemy < 100)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 100)
                    {
                        enemies4.push_back(Enemy4(&enemyTex4, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }


                    for (size_t i = 0; i < enemies4.size(); i++)
                    {
                        enemies4[i].shape.move(-11.f * dt * dtMultiplier, 0.f);
                        enemies4[i].shape.rotate(.9);

                        //enemies[i].shape.move(-6.f * dt * dtMultiplier, 1.5f);
                        //enemies[i].shape.move(-6.f * dt * dtMultiplier, -.005f);
                        //enemies[i].shape.move(-1.f * dt * dtMultiplier, -2.f);


                        if (enemies4[i].shape.getPosition().x <= 0 - enemies4[i].shape.getGlobalBounds().width)
                        {
                            enemies4.erase(enemies4.begin() + i);
                            break;
                        }

                        if (enemies4[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemies4.erase(enemies4.begin() + i);


                            {
                                player.HP--;  //Damaging the Jalopy
                                break;
                            }
                        }
                    }
                }




//boss level starts


                if(score >= 360 && score <= 550 )
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet

//				Out of window bounds
                        if (player.bullets[i].shape.getPosition().x  > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemiesboss.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemiesboss[k].shape.getGlobalBounds()))
                            {
                                if (enemiesboss[k].HP <= 1)
                                {
                                    score += enemiesboss[k].HPMax;//increasing score
                                    enemiesboss.erase(enemiesboss.begin() + 0); //delete enemies
                                }
                                else
                                    enemiesboss[k].HP--;// ENEMY TAKE DAMAGE

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (CreateEnemy < 25)
                    {
                        CreateEnemy += 3.f * dt * dtMultiplier;

                        hudai++;
                    }
//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemiesboss.push_back(Enemyboss(&enemyTexboss, window.getSize()));
                        hudai++;
                        //CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemiesboss.size(); i++)
                    {
                        //enemiesboss[i].shape.rotate(.01);
                        //enemiesboss[i].shape.rotate(-.008);
                        // enemies[i].shape.move(-6.f * dt * dtMultiplier, 0.f);

                        if(hudai == 1)
                        {
                            if(enemiesboss[i].shape.getPosition().x!=200)
                                enemiesboss[i].shape.move(-.5f,0.f);
                        }

                        if (enemiesboss[i].shape.getPosition().x <= 0 - enemiesboss[i].shape.getGlobalBounds().width)
                        {
                            enemiesboss.erase(enemiesboss.begin() + i);
                            break;
                        }

                        if (enemiesboss[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemiesboss.erase(enemiesboss.begin() + i);

                            player.HP--;  //PLAYER TAKE DAMAGE
                            break;
                        }
                    }

                }

                if(score >= 360 && score <= 550 )
                {

                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemiesboss2.push_back(Enemyboss2(&enemyTexboss2, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemiesboss2.size(); i++)
                    {
                        enemiesboss2[i].shape.move(-16.f * dt * dtMultiplier, 0.f);
                        enemiesboss2[i].shape.rotate(1);

                        if (enemiesboss2[i].shape.getPosition().x <= 0 - enemiesboss2[i].shape.getGlobalBounds().width)
                        {
                            enemiesboss2.erase(enemiesboss2.begin() + i);
                            break;
                        }

                        if (enemiesboss2[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemiesboss2.erase(enemiesboss2.begin() + i);

                            player.HP--;  //PLAYER TAKE DAMAGE
                            break;
                        }
                    }
                }





                if(score >= 360 && score <= 550 )
                {

                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemiesboss22.push_back(Enemyboss22(&enemyTexboss22, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemiesboss22.size(); i++)
                    {
                        enemiesboss22[i].shape.move(-16.f * dt * dtMultiplier, .05f);
                        enemiesboss22[i].shape.rotate(1.5);

                        if (enemiesboss22[i].shape.getPosition().x <= 0 - enemiesboss22[i].shape.getGlobalBounds().width)
                        {
                            enemiesboss22.erase(enemiesboss22.begin() + i);
                            break;
                        }

                        if (enemiesboss22[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemiesboss22.erase(enemiesboss22.begin() + i);

                            player.HP--;  //PLAYER TAKE DAMAGE
                            break;
                        }
                    }
                }







                if(score >= 360 && score <= 550 )
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet

//				Out of window bounds
                        if (player.bullets[i].shape.getPosition().x  > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemiesboss3.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemiesboss3[k].shape.getGlobalBounds()))
                            {
                                if (enemiesboss3[k].HP <= 1)
                                {
                                    score += enemiesboss3[k].HPMax;//increasing score
                                    enemiesboss3.erase(enemiesboss3.begin() + 0); //delete enemies3boss
                                }
                                else
                                    enemiesboss3[k].HP--;// ENEMY TAKE DAMAGE

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemiesboss3.push_back(Enemyboss3(&enemyTexboss3, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemiesboss3.size(); i++)
                    {
                        enemiesboss3[i].shape.move(-15.f * dt * dtMultiplier, 0.f);

                        if (enemiesboss3[i].shape.getPosition().x <= 0 - enemiesboss3[i].shape.getGlobalBounds().width)
                        {
                            enemiesboss3.erase(enemiesboss3.begin() + i);
                            break;
                        }

                        if (enemiesboss3[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemiesboss3.erase(enemiesboss3.begin() + i);

                            player.HP--;  //PLAYER TAKE DAMAGE
                            break;
                        }
                    }

                }


                if(score >= 360 && score <= 550 )
                {
                    for (size_t i = 0; i < player.bullets.size(); i++)
                    {
                        //Move
                        player.bullets[i].shape.move(20.f * dt * dtMultiplier, 0.f);//speed of bullet

//				Out of window bounds
                        if (player.bullets[i].shape.getPosition().x  > window.getSize().x)
                        {
                            player.bullets.erase(player.bullets.begin() + i);
                            break;
                        }
                        //Enemy collision
                        for (size_t k = 0; k < enemiesboss4.size(); k++)
                        {
                            if (player.bullets[i].shape.getGlobalBounds().intersects(enemiesboss4[k].shape.getGlobalBounds()))
                            {
                                if (enemiesboss4[k].HP <= 1)
                                {
                                    score += enemiesboss4[k].HPMax;//increasing score
                                    enemiesboss4.erase(enemiesboss4.begin() + 0); //delete enemies4boss
                                }
                                else
                                    enemiesboss4[k].HP--;// ENEMY TAKE DAMAGE

                                player.bullets.erase(player.bullets.begin() + i);
                                break;
                            }
                        }
                    }
                    //Enemy
                    if (CreateEnemy < 25)
                        CreateEnemy += 1.f * dt * dtMultiplier;

//			enemy grow
                    if (CreateEnemy >= 25)
                    {
                        enemiesboss4.push_back(Enemyboss4(&enemyTexboss4, window.getSize()));
                        CreateEnemy = 0;// reset timer
                    }

                    for (size_t i = 0; i < enemiesboss4.size(); i++)
                    {
                        enemiesboss4[i].shape.move(-15.f * dt * dtMultiplier, 0.f);

                        if (enemiesboss4[i].shape.getPosition().x <= 0 - enemiesboss4[i].shape.getGlobalBounds().width)
                        {
                            enemiesboss4.erase(enemiesboss4.begin() + i);
                            break;
                        }

                        if (enemiesboss4[i].shape.getGlobalBounds().intersects(player.shape.getGlobalBounds()))
                        {
                            enemiesboss4.erase(enemiesboss4.begin() + i);

                            player.HP--;  //PLAYER TAKE DAMAGE
                            break;
                        }
                    }

                }



                //for score
                scoreText.setString("Score: " + std::to_string(score));
            }

//		STart Drawing everything now
            window.clear();
            //menu

            tym = cl.getElapsedTime().asSeconds();
            window.draw(sstation);
            // window.draw(snassa);
            window.draw(smoon);
            //window.draw(slife);


            window.draw(player.shape);

            //Bullets
            if((score >= 0 && score < 190) || (score > 220 && score < 1000))
            {
                for (size_t i = 0; i < player.bullets.size(); i++)
                {
                    window.draw(player.bullets[i].shape);
                }

            }


            if(score >= 190 && score <= 220)
            {
                for (size_t i = 0; i < player.bullets2.size(); i++)
                {
                    window.draw(player.bullets2[i].shape);
                }
            }

            //enemy
            if(score < 60)
            {
                for (size_t i = 0; i < enemies.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies[i].HP) + "/" + std::to_string(enemies[i].HPMax));
                    eHpText.setPosition(enemies[i].shape.getPosition().x, enemies[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies[i].shape);
                }
            }




            if(score >= 60 && score < 120)
            {
                for (size_t i = 0; i < enemies2.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies2[i].HP) + "/" + std::to_string(enemies2[i].HPMax));
                    eHpText.setPosition(enemies2[i].shape.getPosition().x, enemies2[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies2[i].shape);
                }
            }



            if(score >= 120 && score < 180)
            {
                for (size_t i = 0; i < enemies2e.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies2e[i].HP) + "/" + std::to_string(enemies2e[i].HPMax));
                    eHpText.setPosition(enemies2e[i].shape.getPosition().x, enemies2e[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies2e[i].shape);
                }
            }

            if(score >= 180 && score < 250)
            {
                for (size_t i = 0; i < enemies3.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies3[i].HP) + "/" + std::to_string(enemies3[i].HPMax));
                    eHpText.setPosition(enemies3[i].shape.getPosition().x, enemies3[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies3[i].shape);
                }
            }

            if(score <= 190 && score >= 220)
            {
                for (size_t i = 0; i < enemies3.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies3[i].HP) + "/" + std::to_string(enemies3[i].HPMax));
                    eHpText.setPosition(enemies3[i].shape.getPosition().x, enemies3[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies3[i].shape);
                }
            }

            if(score >= 250 && score < 360)
            {
                for (size_t i = 0; i < enemies4.size(); i++)
                {
                    eHpText.setString(std::to_string(enemies4[i].HP) + "/" + std::to_string(enemies4[i].HPMax));
                    eHpText.setPosition(enemies4[i].shape.getPosition().x, enemies4[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    //ager line enemy r upor life lekhar jonno use korechi
                    window.draw(eHpText);
                    window.draw(enemies4[i].shape);
                }
            }

            if(score >= 360 && score <= 550 )
            {
                for (size_t i = 0; i < enemiesboss.size(); i++)
                {
                    eHpText.setPosition(enemiesboss[i].shape.getPosition().x, enemiesboss[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    window.draw(enemiesboss[i].shape);
                }
            }

            if(score >= 360 && score <= 550 )
            {
                for (size_t i = 0; i < enemiesboss2.size(); i++)
                {
                    eHpText.setPosition(enemiesboss2[i].shape.getPosition().x, enemiesboss2[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    window.draw(enemiesboss2[i].shape);
                }
            }

            if(score >= 360 && score <= 550 )
            {
                for (size_t i = 0; i < enemiesboss22.size(); i++)
                {
                    eHpText.setPosition(enemiesboss22[i].shape.getPosition().x, enemiesboss22[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    window.draw(enemiesboss22[i].shape);
                }
            }

            if(score >= 360 && score <= 550 )
            {
                for (size_t i = 0; i < enemiesboss3.size(); i++)
                {
                    eHpText.setPosition(enemiesboss3[i].shape.getPosition().x, enemiesboss3[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    window.draw(enemiesboss3[i].shape);
                }
            }

            if(score >= 360 && score <= 550 )
            {
                for (size_t i = 0; i < enemiesboss4.size(); i++)
                {

                    eHpText.setPosition(enemiesboss4[i].shape.getPosition().x, enemiesboss4[i].shape.getPosition().y - eHpText.getGlobalBounds().height);
                    window.draw(enemiesboss4[i].shape);
                }
            }
            window.draw(scoreText);
            window.draw(hpText);
            if((score >= 75 && score <= 85) ||(score >= 150 && score <= 160))
            {
                window.draw(sp);
            }

            if(score >= 0 && score <= 59)
            {
                window.draw(rock);
            }

            if(score >= 60 && score <= 119)
            {
                window.draw(snitch);
            }

            if(score >= 120 && score <= 179)
            {
                window.draw(meteorite);
            }
            if(score >= 180 && score <= 249)
            {
                window.draw(rival);
            }
            if(score >= 250 && score < 360)
            {
                window.draw(throbbing);
            }
            if(score >= 360 && score <= 550)
            {
                window.draw(khelahbe);
            }




            if(mn==1)
            {
                window.draw(menus);
                if(Keyboard :: isKeyPressed(Keyboard::Tab))
                    mn=0;
            }

            if(player.HP==0 || score == 550)
            {
                window.clear();
                window.draw(gameOverText);
                window.draw(gameOverText1);
                score = 0;
                if(Keyboard :: isKeyPressed (Keyboard :: Enter))
                    mn = 1;

            }
        }
        window.display();
    }


    return 0;
}



