## Overview

We own a cinema which sells tickets, merchandise and refreshments.
We need to build a price engine which would calculate the price for the customer.

For this project the codes needs to be written using pure php.
We don't want to use any framework, database integration or 3rd-party tools.

Please demonstrate not only your ability to solve the problem, 
but also your skills in structuring code and making it understandable and extendable.

### Requirements

For the provided customer order generate detailed bill:
  - Order date and time
  - Items list (one per line): product name, category name, quantity, line price
  - Subtotal (sum of the above)
  - Tax (20% applied to all items)
  - Grand Total

Note that multiple items with same name should be grouped together into 1 line.
On top of all we apply 20% tax.
  
### Example:

Customer buys:
   - cinema ticket ($8.25)
   - cinema ticket ($8.25)
   - cola ($3.15)

Expected output:

```
Ordered on 08.11.2021 at 09:02:13
==========================================
cinema ticket x2    [tickets]       $16.50
cola                [refreshments]  $3.15
==========================================
Subtotal:    $19.65
Taxes:       $3.93
Grand Total: $23.58
```

### Boilerplate

There's some code already in place to help you get started.
We've also added some demo data at `data/data.php`.
You can use it as-is or restructure to your liking.

### Running

- install composer `composer install` 
- run `php start.php` 
