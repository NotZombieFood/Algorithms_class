from random import randint
number_addresses = 30 
max_address = 0x40 #0-64
addresses = [randint(0,max_address) for x in range(number_addresses) ]

import cache_tables
# each address is parsed in a way where we can define were to store, easier to implement (one mux, one comparator). Faster but prone to misses
print("Direct Associative")
cache_tables.directAssociative(addresses,4,1)
# each address can be stored at any place in the cache structure, more taxing at number of transistors used and slower
print("random1")
cache_tables.fullAssociative(addresses,4,"RANDOM")
print("FIFO")
cache_tables.fullAssociative(addresses,4,"FIFO")
print("MRU")
cache_tables.fullAssociative(addresses,4,"MRU")
print("LRU")
cache_tables.fullAssociative(addresses,4,"LRU")
print("random2")
cache_tables.fullAssociative(addresses,4,"RANDOM")