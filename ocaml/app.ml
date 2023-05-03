let rec  fibonacci n = 
    match n with 
    | 0 -> 0
    | 1 -> 1
    | _ -> fibonacci(n - 1) + fibonacci(n - 2)

let test_fibonacci () =
  let tests = [
    (0, 0);
    (1, 1);
    (2, 1);
    (3, 2);
    (4, 3);
    (5, 5);
    (10, 55);
    (15, 610);
    (20, 6765);
    (25, 75025);
    (30, 832040);
    (35, 9227465);
    (40, 102334155);
  ] in
  List.iter (fun (n, expected) ->
    let result = fibonacci n in
    if result <> expected then
      Printf.printf "Test failed: fibonacci %d returned %d but expected %d\n" n result expected
    else 
        Printf.printf "Test %d passed! \n" n;
  ) tests

let() = 
    test_fibonacci ();
    print_string "Enter a non-negative number: ";
    let n = read_line () |> int_of_string in
    let result = fibonacci n in
    Printf.printf "The %dth Fibonacci number is %d\n" n result;