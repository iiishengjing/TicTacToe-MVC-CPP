#include "Player.h"
#include <iostream>
#include <limits>

Player::Player(CellState mark) : mark_(mark) {}

CellState Player::getMark() const {
    return mark_;
}

HumanPlayer::HumanPlayer(CellState mark) : Player(mark) {}

std::pair<int, int> HumanPlayer::play(const Board& board) {
    int row, col;
    std::cout << "玩家 " << (mark_ == CellState::X ? 'X' : 'O') << " 请输入行和列 (0-2): ";
    
    while (!(std::cin >> row >> col) || !board.isInside(row, col) || !board.isEmpty(row, col)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "输入无效，请输入空格分隔的行和列 (0-2): ";
    }
    
    return {row, col};
}

AIPlayer::AIPlayer(CellState mark) : Player(mark) {}

std::pair<int, int> AIPlayer::play(const Board& board) {
    // 简单 AI：从左到右、从上到下寻找第一个空格
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (board.isEmpty(row, col)) {
                std::cout << "AI 在 (" << row << ", " << col << ") 落子\n";
                return {row, col};
            }
        }
    }
    return {-1, -1};
}
