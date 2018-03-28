constexpr size_t factorial(size_t N)
{
    return N < 2 ? 1 : (N * factorial(N - 1));
}