template <typename t> concept natural = std::unsigned_integral<t>;
template <typename t> concept number = std::integral<t> || std::floating_point<t>;