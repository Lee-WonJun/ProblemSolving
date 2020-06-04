(defn permutations [s]
  (lazy-seq
   (if (next s)
     (for [head s
           tail (permutations (disj s head))]
          (cons head tail))
          [s])))

(defn is-magic [s]
    (let [[v1 v2 v3 v4 v5 v6 v7 v8 v9] s]
        (= (+ v1 v2 v3) 
           (+ v4 v5 v6) 
           (+ v7 v8 v9)
           (+ v1 v4 v7)
           (+ v2 v5 v8)
           (+ v3 v6 v9)
           (+ v1 v5 v9)
           (+ v3 v5 v7))))

(defn abs [x] (max x (- x)))

(defn calc-list [f s]
    (reduce + (map abs (map - f s))))

; Complete the formingMagicSquare function below.
(defn formingMagicSquare [s]
    (let [f (flatten s)
          magic (filter is-magic (permutations #{1 2 3 4 5 6 7 8 9}))]
          (apply min (map #(calc-list f %) magic))))
