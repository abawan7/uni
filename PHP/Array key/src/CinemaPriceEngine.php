<?php

namespace Fairwalter\Cinema;
include "Collection.php";

class CinemaPriceEngine
{
    /**
     * Contains all test data
     * @see `data/data.php`
     *
     * @var array
     */
    private array $data;

    /**
     * @param array $data
     */
    public function __construct(array $data)
    {
        $this->data = $data;
    }

}
