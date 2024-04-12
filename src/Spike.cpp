//
// Created by User on 2024/3/6.
//

#include "Spike.hpp"

#include <utility>
#include "Util/Image.hpp"
#include "Util/Time.hpp"
#include "CollisionHandler.hpp"
#include "Character.hpp"

Spike::Spike(const std::string &image_path, AudioManager audio_manager) : audio_manager_(std::move(audio_manager)) {
    SetImage(image_path);
    SetZIndex(0);
}

void Spike::SetImage(const std::string &image_path) {
    image_path_ = image_path;
    m_Drawable = std::make_shared<Util::Image>(image_path);
}

void Spike::Update(const std::shared_ptr<Character> &character_) {
    if (CollisionHandler::CheckCollision(character_->GetCollider(), GetCollider()))
        character_->UpdateState(Character::State::Dead);
}

void Spike::Enable() {
    SetVisible(true);
    
}

void Spike::Disable() {
    SetVisible(false);
}
