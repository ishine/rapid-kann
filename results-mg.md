# Vanilla -O3 threads=4
epoch: 1; training cost: 0.0521867 (class error: 8.13%); validation cost: 0.015372 (class error: 2.27%)
Runtime: 175697.296875 (msec) 
Runtime: 176251.937500 (msec)

# CUDA - block_size=8
## Naive    
epoch: 1; training cost: 0.052207 (class error: 8.09%); validation cost: 0.0155179 (class error: 2.13%)
Runtime: 173626.140625 (msec)
Runtime: 173339.875000 (msec)

## Coalesced memory
epoch: 1; training cost: 0.052207 (class error: 8.09%); validation cost: 0.0155179 (class error: 2.13%)
Runtime: 175160.015625 (msec)
Runtime: 174379.234375 (msec)

# CUDA - block_size=16
## Naive
epoch: 1; training cost: 0.052207 (class error: 8.09%); validation cost: 0.0155179 (class error: 2.13%)
Runtime: 174239.984375 (msec)
Runtime: 175127.127393 (msec)

## Coalesced memory
epoch: 1; training cost: 0.052207 (class error: 8.09%); validation cost: 0.0155179 (class error: 2.13%)
Runtime: 174160.031250 (msec)
Runtime: 174056.906250 (msec)