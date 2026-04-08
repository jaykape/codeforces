t = gets.to_i

t.times do
  n, k, x = gets.split.map(&:to_i)

  if x != 1
    puts "YES"
    puts n
    puts ([1] * n).join(" ")
  else
    if k == 1
      puts "NO"
    elsif k == 2
      if n % 2 == 0
        puts "YES"
        puts n / 2
        puts ([2] * (n / 2)).join(" ")
      else
        puts "NO"
      end
    else
      puts "YES"
      if n % 2 == 0
        puts n / 2
        puts ([2] * (n / 2)).join(" ")
      else
        puts (n - 3) / 2 + 1
        puts ([2] * ((n - 3) / 2) + [3]).join(" ")
      end
    end
  end
end

=begin
Case x != 1 we could use 1s n times.
Case x == 1:
   subcase k == 1: No solution
   subcase k == 2: Only even n
   else: Any n > 1
=end
