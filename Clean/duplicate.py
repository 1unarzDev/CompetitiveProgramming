def find_all_duplicates(n):
    # Dictionary to store value -> list of (a,b) pairs that produce it
    power_map = {}
    
    # Calculate all a^b for 2 <= a,b <= n
    for a in range(2, n+1):
        for b in range(2, n+1):
            value = a ** b
            if value not in power_map:
                power_map[value] = []
            power_map[value].append((a, b))
    
    # Find values that appear multiple times
    duplicates = {}
    for value, pairs in power_map.items():
        if len(pairs) > 1:
            duplicates[value] = pairs
    
    return power_map, duplicates

def count_duplicates(n):
    power_map, duplicates = find_all_duplicates(n)
    
    print(f"DEBUG: Checking bounds for n = {n}")
    print(f"Valid range for a and b: 2 to {n} inclusive")
    print()
    
    # Debug: Check if any invalid pairs exist
    invalid_found = False
    for value, pairs in duplicates.items():
        for a, b in pairs:
            if a < 2 or a > n or b < 2 or b > n:
                print(f"ERROR: Invalid pair found: {a}^{b} = {value}")
                invalid_found = True
    
    if not invalid_found:
        print("✓ All pairs are within valid bounds")
    print()
    
    print(f"Analysis for n = {n}:")
    print("=" * 40)
    
    total_combinations = (n-1) * (n-1)
    unique_values = len(power_map)
    duplicate_instances = sum(len(pairs) for pairs in duplicates.values())
    extra_duplicates = duplicate_instances - len(duplicates)  # subtract 1 for each duplicate group
    
    print(f"Total a^b combinations: {total_combinations}")
    print(f"Unique values produced: {unique_values}")
    print(f"Values that have duplicates: {len(duplicates)}")
    print(f"Total duplicate instances: {extra_duplicates}")
    print(f"Verification: {total_combinations} - {extra_duplicates} = {total_combinations - extra_duplicates}")
    print()
    
    # List all duplicate groups
    print("All duplicate groups:")
    duplicate_count = 0
    for i, (value, pairs) in enumerate(sorted(duplicates.items()), 1):
        expressions = [f"{a}^{b}" for a, b in sorted(pairs)]
        print(f"{i}. {' = '.join(expressions)} = {value}")
        duplicate_count += len(pairs) - 1  # Count extra instances
    
    print(f"\nTotal extra duplicate instances: {duplicate_count}")
    
    # List each individual duplicate case with verification
    print(f"\nAll {duplicate_count} individual duplicate cases:")
    case_num = 1
    for value, pairs in sorted(duplicates.items()):
        sorted_pairs = sorted(pairs)
        # The first one is the "original", others are duplicates
        for i in range(1, len(sorted_pairs)):
            a1, b1 = sorted_pairs[0]
            a2, b2 = sorted_pairs[i]
            # Verify the calculation
            val1 = a1 ** b1
            val2 = a2 ** b2
            if val1 == val2 == value:
                status = "✓"
            else:
                status = "✗ ERROR"
            print(f"{case_num}. {a2}^{b2} = {a1}^{b1} = {value} {status}")
            case_num += 1

# Run the analysis
count_duplicates(14)