<?php

namespace Cricket\Simulation\Models;

use Cricket\Simulation\SQL\PlayerSQL;
use Cricket\Simulation\SQL\TeamSQL;

class TeamCollection
{
    private array $teams;

    public function __construct()
    {
        $teamSQL = new TeamSQL();
        $playerSQL = new PlayerSQL();

        $teams = $teamSQL->all();

        foreach ($teams as $team) {
            $teamObj = new Team();
            $teamObj->setId($team['id']);
            $teamObj->setName($team['name']);

            $players = $playerSQL->getByTeamId($teamObj->getId());

            foreach ($players as $player) {
                $playerObj = new Player();
                $playerObj->setId($player['id']);
                $playerObj->setName($player['name']);
                $playerObj->setTeamId($player['team_id']);

                $teamObj->setPlayers($playerObj);
            }

            $this->teams[] = $teamObj;
        }
    }

    /**
     * @return array
     */
    public function getTeams(): array
    {
        return $this->teams;
    }
}
