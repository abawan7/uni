<?php

namespace Cricket\Simulation\SQL;

class TeamSQL
{
    private $conn;

    public function __construct()
    {
        include('config.php');

        $this->conn = $conn;
    }

    public function all() {
        $sql = "SELECT * FROM teams";
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
