t = gets.to_i
t.times do
  a, b, k = gets.split.map(&:to_i)

  g = a.gcd(b)

  if [a / g, b / g].max <= k
    puts 1
  else
    puts 2
  end
end