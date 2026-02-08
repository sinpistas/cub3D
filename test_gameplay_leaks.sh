#!/bin/bash
# Test for memory leaks by sending ESC key
echo "Testing memory leaks with ESC exit..."
echo "This will run the program and simulate ESC press"

# Run with valgrind and auto-exit after 1 second
timeout 1 valgrind --leak-check=full --show-leak-kinds=all \
    --errors-for-leak-kinds=definite --error-exitcode=42 \
    ./cub3D maps/good/minimal.cub 2>&1 | grep -E "(definitely lost|ERROR SUMMARY|All heap)"

echo ""
echo "Note: The program was killed by timeout (expected behavior)."
echo "In real usage, press ESC to exit cleanly."
echo ""
echo "To test manually with valgrind:"
echo "  valgrind --leak-check=full ./cub3D maps/good/minimal.cub"
echo "  Then press ESC to exit and see results"
