<?php

namespace Fairwalter\Cinema;

class Categories
{
    private string $name;
    private string $parentName;

    public function __construct()
    {
        $this->name = "";
        $this->parentName = "";
    }

    /**
     * @param string $name
     */
    public function setName(string $name): void
    {
        $this->name = $name;
    }

    /**
     * @param string $parentName
     */
    public function setParentName(string $parentName): void
    {
        $this->parentName = $parentName;
    }

    /**
     * @return string
     */
    public function getParentName(): string
    {
        return $this->parentName;
    }

    /**
     * @return string
     */
    public function getName(): string
    {
        return $this->name;
    }
}