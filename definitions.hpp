#pragma once

namespace CONST {
    const std::string path = "resources/res/";
    const int screen_width = 768;
    const int screen_height = 1024;
    const float splash_state_show_time = 0.5f;
    const std::string splash_scence_background = path + "splash background.png";
    const std::string main_menu_background = path + "sky.png";
    const std::string game_background = path + "sky.png";
    const std::string game_over_background = path + "sky.png";
    const std::string game_name = path + "title.png";
    const std::string play_button = path + "playbutton.png";
    const std::string land = path + "Land.png";

    // pipes
    const std::string pipe_up = path + "pipeup.png";
    const std::string pipe_down = path + "pipedown.png";
    const float pipe_speed = 200.0f;
    const float pipe_spwan_frequency = 0.5f;
    
    // bird
    const std::string bird_frame1 = path + "bird-01.png";
    const std::string bird_frame2 = path + "bird-02.png";
    const std::string bird_frame3 = path + "bird-03.png";
    const std::string bird_frame4 = path + "bird-04.png";
}

