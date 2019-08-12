#pragma once

namespace CONST {
    const std::string path_res = "resources/res/";
    const int screen_width = 768;
    const int screen_height = 1024;
    const float splash_state_show_time = 0.5f;
    const std::string splash_scence_background = path_res + "splash background.png";
    const std::string main_menu_background = path_res + "sky.png";
    const std::string game_background = path_res + "sky.png";
    const std::string game_over_background = path_res + "sky.png";
    const std::string game_name = path_res + "title.png";
    const std::string play_button = path_res + "playbutton.png";
    const std::string land = path_res + "Land.png";

    // pipes
    const std::string pipe_up = path_res + "pipeup.png";
    const std::string pipe_down = path_res + "pipedown.png";
    const std::string scoring_pipe = path_res + "InvisibleScoringPipe.png";
    const float pipe_speed = 200.0f;
    const float pipe_spwan_frequency = 2.5f;
    
    // bird
    const std::string bird_frame1 = path_res + "bird-01.png";
    const std::string bird_frame2 = path_res + "bird-02.png";
    const std::string bird_frame3 = path_res + "bird-03.png";
    const std::string bird_frame4 = path_res + "bird-04.png";
    const float bird_animation_duration = 0.5f;
    const int bird_still = 0;
    const int bird_falling = 1;
    const int bird_flying = 2;
    const float gravity = 350.0f;
    const float flying_speed = 350.0f;
    const float flying_duration = 0.25f;
    const float rotation_speed = 100.0f;
    
    const float flash_speed = 1500.0f;
    
    const std::string font = "resources/fonts/FlappyFont.ttf";
    
    const std::string game_over_title = path_res + "Game-Over-Title.png";
    const std::string game_over_body = path_res + "Game-Over-Body.png";
    const float time_before_game_over = 0.5f;
    
    const std::string bronze_medal = path_res + "Bronze-Medal.png";
    const std::string silver_medal = path_res + "Silver-Medal.png";
    const std::string gold_medal = path_res + "Gold-Medal.png";
    const std::string platinum_medal = path_res + "Platinum-Medal.png";
    
    
    // scores medals
    const int bronze_score = 0;
    const int silver_score = 5;
    const int gold_score = 7;
    const int platinum_score = 10;
    
    
    // sounds
    const std::string path_aud = "resources/audio/";
    const std::string sound_hit = path_aud + "Hit.wav";
    const std::string sound_point = path_aud + "Point.wav";
    const std::string sound_Wing = path_aud + "Wing.wav";
    
    
}

enum EnumGameState
{
    eReady,
    ePlaying,
    eGameOver
};

