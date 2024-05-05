<?php

namespace Cricket\Simulation\SQL;

class PlayerSQL
{
    private $conn;

    public function __construct()
    {
        include('config.php');

        $this->conn = $conn;
    }

    public function getByTeamId($teamId) {
        $sql = "SELECT * FROM players where team_id=$teamId";
        $result = $this->conn->query($sql);

        $players = [];

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                $players[] = $row;
            }
        }

        return $players;
    }

    public function all() {
        $sql = "SELECT * FROM players";
        $result = $this->conn->query($sql);

        $teams = [];

        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                $teams[] = $row;
            }
        }

        return $teams;
    }
}
