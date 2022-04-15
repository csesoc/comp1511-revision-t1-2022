height = int(input())
layers = []
total = 0

for _ in range(height):
    new_layer = int(input())
    layers.append(new_layer)

    reduce_index = len(layers) - 1

    while new_layer * reduce_index > total:
        total -= layers[-2]
        layers.pop(-2)
        reduce_index -= 1

    total += new_layer

print(len(layers))
