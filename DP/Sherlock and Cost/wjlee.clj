(defn abs [x] (max (- x) x))

(defn fun ([v] (fun v 0 0))
  ( [v dp1 dp2]
    (if (= (count v) 1)
      (max dp1 dp2)
      (let [f (first v)
            s (second v)
            dp1-re  (max dp1 (+ dp2 (abs (- 1 f))))
            dp2-re  (max (+ dp1 (abs (- 1 s))) (+ dp2 (abs (- f s))))]
        (recur (rest v) dp1-re dp2-re)))))

(defn cost [B]
    (fun B)
)
