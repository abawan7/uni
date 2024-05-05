<?php

namespace Cricket\Simulation\Models;

class Team
{
    private int $id;
    private string $name;
    private array $players;

    /**
     * @param Player $player
     */
    public function setPlayers(Player $player): void
    {
        $this->players[] = $player;
    }

    /**
     * @return array
     */
    public function getPlayers(): array
    {
        return $this->players;
    }

    /**
     * @param int $id
     */
    public function setId(int $id): void
    {
        $this->id = $id;
    }

    /**
     * @return int
     */
    public function getId(): int
    {
        return $this->id;
    }

    /**
     * @param string $name
     */
    public function setName(string $name): void
    {
        $this->name = $name;
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }
}