constexpr auto factorial(auto N) -> decltype(N)
{
    return N ? (N * factorial(N - 1)) : 1;
}