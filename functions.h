constexpr auto factorial(size_t N) -> decltype(N)
{
    return N ? (N * factorial(N - 1)) : 1;
}