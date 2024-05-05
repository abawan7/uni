<?php
require 'vendor/autoload.php';
$data = require('data/data.php');

$engine = new \Fairwalter\Cinema\Collections($data);

//ORDER:
$find = 'gold';
return $engine->getOrderBill($find)."\n";
