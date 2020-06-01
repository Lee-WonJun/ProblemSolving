(defn exp [x n]
  (reduce * (repeat n x)))

(def mod-value (+ 7 (exp 10 9)))
(defn my-mod [x] (mod x mod-value))

(defn tail-count [d-avail d-number-one d-answer acc k n]
    (let [avail (my-mod (* k d-avail))
          number-one (my-mod (- d-avail d-number-one))
          answer (my-mod (- avail number-one))]
          (if (= acc n) d-answer
          (recur avail number-one answer (inc acc) k n)
          )))

(defn count-dp [n k x]
    (let [n-n (- n 2)
          n-k (dec k)
          n-o (if (= x 1) 1 0)]
          (tail-count 1 n-o 1 0 n-k n-n))
)
