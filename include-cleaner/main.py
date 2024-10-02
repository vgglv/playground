import os

include_file = open('input.txt', 'r')
lines = include_file.readlines()
hashmap = {}
for line in lines:
    if '.cpp' in line:
        continue
    s = line.split('#include')
    if len(s) < 2:
        continue
    include_only = s[1].split('/')
    cleaned = include_only[-1].replace('"', '').replace('\n', '').replace(' ', '')
    if cleaned in hashmap:
        hashmap[cleaned] += 1
    else:
        hashmap[cleaned] = 1
sorted_hashmap = dict(sorted(hashmap.items(), key=lambda item: item[1], reverse=True))
for value in sorted_hashmap:
    print(value, sorted_hashmap[value])
include_file.close()