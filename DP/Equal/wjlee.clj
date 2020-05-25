(def m-m
  (memoize (fn [x]
           (condp = x
             0 0
             1 1
             2 1
             3 2
             4 2
             5 1
             (inc (min (m-m (- x 1) ) (m-m (- x 2)) (m-m (- x 5)) ) )))))

(defn add-and-m [arr add]
    (->> arr
         (map #(+ add %))
         (map m-m)
         (reduce + )))

; Complete the equal function below.
(defn equal [arr]
  (let [m   (apply min arr)
        mi  (map #(- % m) arr)
        x   (add-and-m mi 0) 
        y   (add-and-m mi 1) 
        z   (add-and-m mi 2) ]
    (min x y z )))
