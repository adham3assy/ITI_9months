def fractional_knapsack(items, capacity):
    
    ratios = [(v/w, v, w) for v, w in items]
    ratios.sort(reverse=True)
    
    total_value = 0
    for ratio, value, weight in ratios:
        if capacity >= weight:
            total_value += value
            capacity -= weight
        else:
            total_value += value * (capacity / weight)
            break
    return total_value



items = [(60, 10), (100, 20), (120, 30)]  
capacity = 50
print("Maximum value:" , fractional_knapsack(items, capacity))