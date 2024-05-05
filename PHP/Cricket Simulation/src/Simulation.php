<?php

namespace Cricket\Simulation;

use Cricket\Simulation\Models\Batsman;
use Cricket\Simulation\Models\Bowler;
use Cricket\Simulation\Models\ScoreChart;
use Cricket\Simulation\Models\TeamCollection;

class Simulation
{
    private array $teams;

    public function __construct(TeamCollection $teamCollection)
    {
        $this->teams = $teamCollection->getTeams();
    }

    public function simulate()
    {
        $balls = 0;
        $batIndex = 0;
        $bowlerIndex = 4;
        $matchStats = new ScoreChart();

        $batsman = new Batsman();
        $batsman->setPlayer($this->teams[0]->getPlayers()[$batIndex]);

        while ($balls < 24) {
            if ($batIndex > 4) {
                break;
            }

            $bowler = new Bowler();
            $bowler->setPlayer($this->teams[1]->getPlayers()[$bowlerIndex]);

            $over = 0;
            $out = false;

            while ($over < 6) {
                if ($out) {
                    $batIndex++;
                    $matchStats->setBatman($batsman);
                    $batsman = new Batsman();
                    $batsman->setPlayer($this->teams[0]->getPlayers()[$batIndex]);
                }

                $ball = rand(0, 6);

                switch ($ball) {
                    case 0:
                        $batsman->incrementDots();
                        $batsman->incrementBalls();
                        $bowler->incrementBalls();
                        break;

                    case 1:
                        $batsman->setScore(1);
                        $batsman->incrementBalls();
                        $bowler->setScore(1);
                        $bowler->incrementBalls();
                        $matchStats->setTotalScore(1);
                        break;

                    case 2:
                        $batsman->setScore(2);
                        $batsman->incrementBalls();
                        $bowler->setScore(2);
                        $bowler->incrementBalls();
                        $matchStats->setTotalScore(2);
                        break;

                    case 3:
                        $batsman->setScore(3);
                        $batsman->incrementBalls();
                        $bowler->setScore(3);
                        $bowler->incrementBalls();
                        $matchStats->setTotalScore(3);
                        break;

                    case 4:
                        $batsman->incrementFours();
                        $batsman->incrementBalls();
                        $batsman->setScore(4);
                        $bowler->incrementFours();
                        $bowler->incrementBalls();
                        $bowler->setScore(4);
                        $matchStats->setTotalScore(4);
                        break;

                    case 5:
                        $batsman->incrementBalls();
                        $bowler->incrementBalls();
                        $bowler->incrementWickets();
                        $matchStats->setWickets();
                        $out = true;
                        break;

                    case 6:
                        $batsman->incrementSixes();
                        $batsman->incrementBalls();
                        $batsman->setScore(6);
                        $bowler->incrementSixes();
                        $bowler->incrementBalls();
                        $bowler->setScore(6);
                        $matchStats->setTotalScore(6);
                        break;
                }
                $over++;
                $balls++;
            }
            if ($balls == 23){
                $matchStats->setBatman($batsman);
            }
            $matchStats->setBowler($bowler);
            $bowlerIndex--;
        }
        echo("<pre>");
        print_r($matchStats->getBatman());
        print_r(($matchStats->getBowler()));
        echo("</pre>");
        echo "Total Score: " . $matchStats->getTotalScore();
    }

}