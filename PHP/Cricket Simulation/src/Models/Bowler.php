<?php

namespace Cricket\Simulation\Models;

class Bowler extends Player
{
    private Player $player;

    private int $score = 0;

    private int $balls = 0;

    private int $sixes = 0;

    private int $fours = 0;

    private int $dots = 0;

    private int $wickets = 0;

    /**
     * @param Player $player
     */
    public function setPlayer(Player $player): void
    {
        $this->player = $player;
    }

    public function incrementSixes(): void
    {
        $this->sixes++;
    }

    public function incrementFours(): void
    {
        $this->fours++;
    }

    public function incrementDots(): void
    {
        $this->dots++;
    }

    public function incrementBalls(): void
    {
        $this->balls++;
    }

    public function incrementWickets(): void
    {
        $this->wickets++;
    }

    /**
     * @param int $score
     */
    public function setScore(int $score): void
    {
        $this->score += $score;
    }
}