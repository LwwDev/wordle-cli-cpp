#include "game.h"
#include <iostream>
<<<<<<< HEAD
#include <random>

void Game::menu() {
  char opt;
  std::cout << "==================\n";
  std::cout << "===== Wordle =====\n";
  std::cout << "==================\n\n";
  std::cout << "1. Play!\n";
  std::cout << "2. Exit.\n";
  std::cin >> opt;

  switch (opt) {
  case '1':
    start();
    break;
  case '2':
    return;
  default:
    std::cout << "not an option";
    break;
  }
}

void Game::start() { 
  char colors[5];
  std::string secret_word = picker(); 
  std::string guess = getValidGuess();
  evaluateGuess(guess, secret_word, colors);
  updateBoard();
}

void Game::evaluateGuess(const std::string& guess, const std::string& secret_word, char colors[5]) {
  for(int i = 0; i < 5; i++){
  }
}

void Game::updateBoard() {}

std::string Game::getValidGuess() {
  while (true) {
    std::string currentGuess;
    std::cout << "Type a 5 letter word: ";
    std::getline(std::cin, currentGuess);
    
    if (currentGuess.length() == 5){
      return currentGuess;
    }
  }
}

std::string Game::picker() {
  std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(0, words.size() - 1);
  std::string secret_word = words[dist(gen)];
  return secret_word;
}

Game::Game() {
  words = {
    "about", "above", "abuse", "actor", "acute", "admit", "adopt", "adult",
    "after", "again", "agent", "agree", "ahead", "alarm", "album", "alert",
    "align", "alike", "alive", "allow", "alone", "along", "alter", "angel",
    "anger", "angle", "angry", "apart", "apple", "apply", "arena", "argue",
      "arise", "array", "aside", "asset", "audio", "avoid", "awake", "award",
      "aware", "badly", "baker", "bases", "basic", "basis", "beach", "began",
      "begin", "being", "below", "bench", "billy", "birth", "black", "blame",
      "blind", "block", "blood", "board", "boost", "booth", "bound", "brain",
      "brand", "bread", "break", "breed", "brief", "bring", "broad", "broke",
      "brown", "build", "built", "buyer", "cable", "calif", "carry", "catch",
      "cause", "chain", "chair", "chart", "chase", "cheap", "check", "chest",
      "chief", "child", "china", "chose", "civil", "claim", "class", "clean",
      "clear", "click", "clock", "close", "coach", "coast", "could", "count",
      "court", "cover", "crack", "craft", "crash", "crazy", "cream", "crime",
      "cross", "crowd", "crown", "crude", "cycle", "daily", "dance", "dated",
      "dealt", "death", "debut", "delay", "depth", "doing", "doubt", "dozen",
      "draft", "drama", "drank", "drawn", "dream", "dress", "drill", "drink",
      "drive", "drove", "dying", "eager", "early", "earth", "eight", "elite",
      "empty", "enemy", "enjoy", "enter", "entry", "equal", "error", "event",
      "every", "exact", "exist", "extra", "faith", "false", "fault", "fiber",
      "field", "fifth", "fifty", "fight", "final", "first", "fixed", "flash",
      "fleet", "floor", "fluid", "focus", "force", "forth", "forty", "forum",
      "found", "frame", "frank", "fraud", "fresh", "front", "fruit", "fully",
      "funny", "giant", "given", "glass", "globe", "going", "grace", "grade",
      "grand", "grant", "grass", "great", "green", "gross", "group", "grown",
      "guard", "guess", "guest", "guide", "happy", "harry", "heart", "heavy",
      "hence", "henry", "horse", "hotel", "house", "human", "ideal", "image",
      "index", "inner", "input", "issue", "japan", "jimmy", "joint", "jones",
      "judge", "known", "label", "large", "laser", "later", "laugh", "layer",
      "learn", "lease", "least", "leave", "legal", "lemon", "level", "lewis",
      "light", "limit", "links", "lives", "local", "logic", "loose", "lower",
      "lucky", "lunch", "lying", "magic", "major", "maker", "march", "maria",
      "match", "maybe", "mayor", "meant", "media", "metal", "might", "minor",
      "minus", "mixed", "model", "money", "month", "moral", "motor", "mount",
      "mouse", "mouth", "movie", "music", "needs", "never", "newly", "night",
      "noise", "north", "noted", "novel", "nurse", "occur", "ocean", "offer",
      "often", "order", "other", "ought", "paint", "panel", "paper", "party",
      "peace", "peter", "phase", "phone", "photo", "piece", "pilot", "pitch",
      "place", "plain", "plane", "plant", "plate", "point", "pound", "power",
      "press", "price", "pride", "prime", "print", "prior", "prize", "proof",
      "proud", "prove", "queen", "quick", "quiet", "quite", "radio", "raise",
      "range", "rapid", "ratio", "reach", "ready", "refer", "right", "rival",
      "river", "robin", "roger", "roman", "rough", "round", "route", "royal",
      "rural", "scale", "scene", "scope", "score", "sense", "serve", "seven",
      "shall", "shape", "share", "sharp", "sheet", "shelf", "shell", "shift",
      "shirt", "shock", "shoot", "short", "shown", "sight", "since", "sixth",
      "sixty", "sized", "skill", "sleep", "slide", "small", "smart", "smile",
      "smith", "smoke", "solid", "solve", "sorry", "sound", "south", "space",
      "spare", "speak", "speed", "spend", "spent", "split", "spoke", "sport",
      "staff", "stage", "stake", "stand", "start", "state", "steam", "steel",
      "stick", "still", "stock", "stone", "stood", "store", "storm", "story",
      "strip", "stuck", "study", "stuff", "style", "sugar", "suite", "super",
      "sweet", "table", "taken", "taste", "taxes", "teach", "terry", "texas",
      "thank", "theft", "their", "theme", "there", "these", "thick", "thing",
      "think", "third", "those", "three", "threw", "throw", "tight", "times",
      "title", "today", "topic", "total", "touch", "tough", "tower", "track",
      "trade", "train", "treat", "trend", "trial", "tribe", "trick", "tried",
      "tries", "troop", "truck", "truly", "trust", "truth", "twice", "under",
      "undue", "union", "unity", "until", "upper", "upset", "urban", "usage",
      "usual", "valid", "value", "video", "virus", "visit", "vital", "vocal",
      "voice", "waste", "watch", "water", "wheel", "where", "which", "while",
      "white", "whole", "whose", "woman", "women", "world", "worry", "worse",
      "worst", "worth", "would", "wound", "write", "wrong", "wrote", "young",
      "youth"};
=======


void Game::menu(){
    char opt;
    std::cout << "==================\n";
    std::cout << "===== Wordle =====\n";
    std::cout << "==================\n\n";  
    std::cout << "1. Play!\n";  
    std::cout << "2. Exit.\n";  
    std::cin >> opt;

    switch(opt){
        case '1': start();
        case '2': return;
        default: std::cout << "not an option"; break;
    }
}

void start(){
    std::cout << "test";
}






















Game::Game(){
    words = {
    "about", "above", "abuse", "actor", "acute",
    "admit", "adopt", "adult", "after", "again",
    "agent", "agree", "ahead", "alarm", "album",
    "alert", "align", "alike", "alive", "allow",
    "alone", "along", "alter", "angel", "anger",
    "angle", "angry", "apart", "apple", "apply",
    "arena", "argue", "arise", "array", "aside",
    "asset", "audio", "avoid", "awake", "award",
    "aware", "badly", "baker", "bases", "basic",
    "basis", "beach", "began", "begin", "being",
    "below", "bench", "billy", "birth", "black",
    "blame", "blind", "block", "blood", "board",
    "boost", "booth", "bound", "brain", "brand",
    "bread", "break", "breed", "brief", "bring",
    "broad", "broke", "brown", "build", "built",
    "buyer", "cable", "calif", "carry", "catch",
    "cause", "chain", "chair", "chart", "chase",
    "cheap", "check", "chest", "chief", "child",
    "china", "chose", "civil", "claim", "class",
    "clean", "clear", "click", "clock", "close",
    "coach", "coast", "could", "count", "court",
    "cover", "crack", "craft", "crash", "crazy",
    "cream", "crime", "cross", "crowd", "crown",
    "crude", "cycle", "daily", "dance", "dated",
    "dealt", "death", "debut", "delay", "depth",
    "doing", "doubt", "dozen", "draft", "drama",
    "drank", "drawn", "dream", "dress", "drill",
    "drink", "drive", "drove", "dying", "eager",
    "early", "earth", "eight", "elite", "empty",
    "enemy", "enjoy", "enter", "entry", "equal",
    "error", "event", "every", "exact", "exist",
    "extra", "faith", "false", "fault", "fiber",
    "field", "fifth", "fifty", "fight", "final",
    "first", "fixed", "flash", "fleet", "floor",
    "fluid", "focus", "force", "forth", "forty",
    "forum", "found", "frame", "frank", "fraud",
    "fresh", "front", "fruit", "fully", "funny",
    "giant", "given", "glass", "globe", "going",
    "grace", "grade", "grand", "grant", "grass",
    "great", "green", "gross", "group", "grown",
    "guard", "guess", "guest", "guide", "happy",
    "harry", "heart", "heavy", "hence", "henry",
    "horse", "hotel", "house", "human", "ideal",
    "image", "index", "inner", "input", "issue",
    "japan", "jimmy", "joint", "jones", "judge",
    "known", "label", "large", "laser", "later",
    "laugh", "layer", "learn", "lease", "least",
    "leave", "legal", "lemon", "level", "lewis",
    "light", "limit", "links", "lives", "local",
    "logic", "loose", "lower", "lucky", "lunch",
    "lying", "magic", "major", "maker", "march",
    "maria", "match", "maybe", "mayor", "meant",
    "media", "metal", "might", "minor", "minus",
    "mixed", "model", "money", "month", "moral",
    "motor", "mount", "mouse", "mouth", "movie",
    "music", "needs", "never", "newly", "night",
    "noise", "north", "noted", "novel", "nurse",
    "occur", "ocean", "offer", "often", "order",
    "other", "ought", "paint", "panel", "paper",
    "party", "peace", "peter", "phase", "phone",
    "photo", "piece", "pilot", "pitch", "place",
    "plain", "plane", "plant", "plate", "point",
    "pound", "power", "press", "price", "pride",
    "prime", "print", "prior", "prize", "proof",
    "proud", "prove", "queen", "quick", "quiet",
    "quite", "radio", "raise", "range", "rapid",
    "ratio", "reach", "ready", "refer", "right",
    "rival", "river", "robin", "roger", "roman",
    "rough", "round", "route", "royal", "rural",
    "scale", "scene", "scope", "score", "sense",
    "serve", "seven", "shall", "shape", "share",
    "sharp", "sheet", "shelf", "shell", "shift",
    "shirt", "shock", "shoot", "short", "shown",
    "sight", "since", "sixth", "sixty", "sized",
    "skill", "sleep", "slide", "small", "smart",
    "smile", "smith", "smoke", "solid", "solve",
    "sorry", "sound", "south", "space", "spare",
    "speak", "speed", "spend", "spent", "split",
    "spoke", "sport", "staff", "stage", "stake",
    "stand", "start", "state", "steam", "steel",
    "stick", "still", "stock", "stone", "stood",
    "store", "storm", "story", "strip", "stuck",
    "study", "stuff", "style", "sugar", "suite",
    "super", "sweet", "table", "taken", "taste",
    "taxes", "teach", "terry", "texas", "thank",
    "theft", "their", "theme", "there", "these",
    "thick", "thing", "think", "third", "those",
    "three", "threw", "throw", "tight", "times",
    "title", "today", "topic", "total", "touch",
    "tough", "tower", "track", "trade", "train",
    "treat", "trend", "trial", "tribe", "trick",
    "tried", "tries", "troop", "truck", "truly",
    "trust", "truth", "twice", "under", "undue",
    "union", "unity", "until", "upper", "upset",
    "urban", "usage", "usual", "valid", "value",
    "video", "virus", "visit", "vital", "vocal",
    "voice", "waste", "watch", "water", "wheel",
    "where", "which", "while", "white", "whole",
    "whose", "woman", "women", "world", "worry",
    "worse", "worst", "worth", "would", "wound",
    "write", "wrong", "wrote", "young", "youth"
};
>>>>>>> af305c9083871968755d3fa7d13a7d92e20064c4
}
