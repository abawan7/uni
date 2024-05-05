<?php

namespace Cricket\Simulation\Models;

class ScoreChart
{
    private array $batman;

    private array $bowler;

    private int $wickets = 0;

    private int $totalScore = 0;

    /**
     * @param Batsman $batman
     */
    public function setBatman(Batsman $batman): void
    {
        $this->batman[] = $batman;
    }

    /**
     * @return array
     */
    public function getBatman(): array
    {
        return $this->batman;
    }
    /**
     * @param int $totalScore
     */

    /**
     * @param Bowler $bowler
     */
    public function setBowler(Bowler $bowler): void
    {
        $this->bowler[] = $bowler;
    }

    /**
     * @return array
     */
    public function getBowler(): array
    {
        return $this->bowler;
    }

    public function setTotalScore(int $totalScore): void
    {
        $this->totalScore += $totalScore;
    }

    /**
     * @return int
     */
    public function getTotalScore(): int
    {
        return $this->totalScore;
    }

    public function setWickets(): void
    {
        $this->wickets++;
    }

    /**
     * @return int
     */
    public function getWickets(): int
    {
        return $this->wickets;
    }
}