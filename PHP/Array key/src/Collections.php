<?php

namespace Fairwalter\Cinema;
include "Categories.php";

class Collections
{
    private array $data;
    private array $categories;
    /**
     * @param array $categories
     */
    /**
     * @param array $data
     */
    public function __construct(array $data)
    {
        $this->data = $data;
    }

    public function findParent($array, $parent, $index): bool
    {
        foreach ($array as $key => $arr) {
            if (is_array($arr)) {
                $parent = $key;
                foreach ($arr as $value => $array) {

                    $this->categories[$value][$index] = new Categories();
                    if (is_array($array)) {
                        $this->categories[$value][$index]->setName($value);
                        $this->categories[$value][$index]->setParentName($parent);
                    }

                    else {
                        $this->categories[$value][$index]->setParentName($parent);
                        $this->categories[$value][$index]->setName($array);
                    }
                }

                $index += 1;

                $found = $this->findParent($arr, $key, $index);
                if ($found !== false) {
                    return $found;
                }
            }
        }
        return false;
    }

    public function getOrderBill($find): string
    {
        $parent = "";
        foreach ($this->data['products'] as $key => $value) {
            $parent = $key;
        }
        $this->findParent($this->data['products'], $parent, 0);
        return 0;
    }
}