(defn int-div [v] (int (/ v 2)))

(defn make-avail-helper [r n k]
  (let [repeat-k (repeat k k)
        repeat-k-minus (repeat k (- k))
        repeat-k-and-k-minus (concat repeat-k repeat-k-minus)
        mapped (take n (flatten (repeat (inc (/ n (* 2 k))) repeat-k-and-k-minus)))]
    (map + r mapped)))

(defn make-avail [n k]
  (let [r (range 1 (inc n))]
    (if (zero? k) r (make-avail-helper r n k))))

(defn absolutePermutation [n k]
  (let [avail-s (make-avail n k)
        sort-avail (sort avail-s)]
    (if (= sort-avail (range 1 (inc n)))  avail-s [-1])))
