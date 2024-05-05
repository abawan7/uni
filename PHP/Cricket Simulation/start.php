<?php

require 'vendor/autoload.php';

use Cricket\Simulation\Models\TeamCollection;
use Cricket\Simulation\Simulation;

$teamCollection = new TeamCollection();
$simulation = new Simulation($teamCollection);

$simulation->simulate();
